import re
import argparse
from datetime import datetime
from datetime import timedelta
import sys as s
import time
from itertools import groupby

class process_cal:
    def __init__(self, filename):
        self.filename = filename
        
    def get_events_for_day(self, date):
        all_date = self.scanText(self.filename,date)
        
        
        #DATE store the input date range
        # we going the file with a specify date. We append the events to the list if the day is equal to the date

        DATE = re.search(r"(\d\d\d\d-\d\d-\d\d)",str(date))
        DATE = DATE.group(0)
        DATE = datetime.strptime(DATE,"%Y-%m-%d")
        DATE = DATE.strftime("%Y%m%d")
        
        filterDates = self.filterDate(all_date,DATE)
        
        return filterDates
    #printOutput def is contain Docstring format for printing event with no rrule
    def printOutput(self, x):
        
        date = x["DTSTART"]
        date_end = x["DTEND"]

        dateTo = self.printList_TIME_START(date)
        dateFrom = self.printList_TIME_END(date_end)
        dateFormat = self.dateFormat(date)

        Lbracket = "{"
        Rbracket = "}"
        
        
        dashes = self.dashLine(len(dateFormat))
        output = f'''{dateFormat}
{dashes}
{dateTo} {dateFrom} {x["SUMMARY"]} {{{Lbracket}{x["LOCATION"]}{Rbracket}}}'''
        return output
        
    
        
    # DRAW DASH LINE
    def dashLine(self, sizeOfFormat):
        j=0
        dashes = ""
        while j < sizeOfFormat:
            dashes = dashes + "-" 
            j += 1

        return dashes

    #change the dateFormat with out RRULE
    def dateFormat(self,date):
        
        date = datetime.strptime(date,"%Y%m%dT%H%M%S")
        date = date.strftime("%B %d, %Y (%a)")
        return date
    #change the dateFormat that contain RRULE
    def dateFormatRRULE(self,date):
        
        date = datetime.strptime(date,"%Y%m%d")
        date = date.strftime("%B %d, %Y (%a)")
        return date
    #filterDate is for filter the dictionary text which store the information we need for given file.
    # and to this, I choose to compare the days string if they are equal or not
    def filterDate(self, all_date, DATE):
        
        output = ""
        recordedEvents = []
        for x in all_date:
            
            #if the event contain RRULE, go to here
            if "RRULE" in x:
                rrule = x["RRULE"]
                rrule_split = rrule[-24:]
                rrule_split = re.split(";", rrule_split)

                until = re.search(r'\d\d\d\d\d\d\d\dT\d\d\d\d\d\d', str(rrule_split))
                until = ("%s" % until.group(0))

                rrule_split = re.findall(r'BYDAY=(.+)', str(rrule_split))

                rrule_split = re.sub("']", "", rrule_split[0])
                

                dtstart_day = datetime.strptime(DATE,"%Y%m%d")
                dtstart_day = dtstart_day.strftime("%a")
                dtstart_day = self.day_convert(dtstart_day)
                
                if rrule_split == dtstart_day:
                    output = self.printRRULE(x,DATE,until)
                    event = self.printEvent(x, until)
                    recordedEvents.append(event)
        
                    # if event do not contain rrule, go to here
            else:
                fileDate = re.split("T",x["DTSTART"], 1)[0]
                
                if fileDate == DATE:
                    output = self.printOutput(x)
            
        for event in recordedEvents:
                            
            output+=event
        return output
            
    #printEvent def is contain Docstring format for printing rrule contain event
    def printEvent(self, x, until):
        
        dateTo = self.printList_TIME_START(x["DTSTART"])
        dateFrom = self.printList_TIME_END(x["DTEND"])
        Lbracket = "{"
        Rbracket = "}"
        outputLine = f'''
{dateTo} {dateFrom} {x["SUMMARY"]} {{{Lbracket}{x["LOCATION"]}{Rbracket}}}'''
        return outputLine

    def printRRULE(self, x, DATE,until):
        dateFormat = self.dateFormatRRULE(DATE)
        
        
        dashes = self.dashLine(len(dateFormat))
        output = f'''{dateFormat}
{dashes}'''

        return output

    #this funciton convert the day string.
    def day_convert(self,dtstart_day):
        if dtstart_day == 'Mon':
            return 'MO'
        if dtstart_day == 'Tue':
            return 'TU'
        if dtstart_day == 'Wed':
            return 'WE'
        if dtstart_day == 'Thu':
            return 'TH'
        if dtstart_day == 'Fri':
            return 'FR'
        if dtstart_day == 'Sat':
            return 'SA'
        if dtstart_day == 'Sun':
            return 'SU'




    #this function create the output of start time format
    def printList_TIME_START(self, dt_start):
        
        dtstart = datetime.strptime(dt_start,"%Y%m%dT%H%M%S")

        dtstart = re.sub("e0", " ", dtstart.strftime("e%I:%M %p to"))
        dtstart = re.sub("e", "", dtstart)
        # dtstart = dtstart.strftime("e%I:%M %p to").replace("e0", " ").replace("e", "")

        return dtstart
    #this function create the output of end time format
    def printList_TIME_END(self, dt_end):
        
        dtend = datetime.strptime(dt_end,"%Y%m%dT%H%M%S")
        dtend = re.sub("e0", " ", dtend.strftime("e%I:%M %p:"))
        dtend = re.sub("e", "", dtend)
        return dtend
    # this def scanText is for scan the given file and make it into Dictionary form
    def scanText(self, filename, date):

        textFile = open(filename, "r")

        fileLine = []
        event = {}
        counter = 0
        with textFile as f:

            i = 0
            for line in f:
                #creat dictionary
                if line == '\n':
                    continue
                line = re.sub('\n', "", line)
                key = re.split(":", line)[0]#line.split(":")[0]
                value = re.split(":", line)[1]

                if line == "BEGIN:VEVENT" or counter == 1: 
                    counter = 1
                    event[key] = value 
                    
                if line == "END:VEVENT": 
                    counter = 0
                    
                    fileLine.append(event)
                    
                    event = {} 
                    
                i += 1 
        return fileLine

