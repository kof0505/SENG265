#!/usr/bin/env python3

import argparse
from datetime import datetime
from datetime import timedelta
import sys as s
import time
from itertools import groupby




# create dashline with right number of dash, depends on the output
def dashLine(sizeOfFormat):
    j=0
    while j < sizeOfFormat:
            print("-", end = '')
            j += 1

    print("")
#this function create a date start, datetime to string
def dateConvert_start(dtstart):
    # print(dtstart)
    dtstart = datetime.strptime(dtstart,"%Y%m%dT%H%M%S")
    dtstart = dtstart.strftime("%B %d, %Y (%a)")
    return dtstart
#this function create a date end, datetime to string
def dateConvert_end(dt_end):
    dt_end = datetime.strptime(dt_end,"%Y%m%dT%H%M%S")
    dt_end = dt_end.strftime("%B %d, %Y (%a)")
    # dt_end = dt_end.strftime()
    return dt_end
#this function create the output of start time format inside the filterDate
def timeConvert_start(dt_start):
    
    dtstart = datetime.strptime(dt_start,"%Y%m%dT%H%M%S")
    dtstart = dtstart.strftime("e%I:%M %p to").replace("e0", " ").replace("e", "")
    return dtstart

#this function create the output of end time format inside the filterDate
def timeConvert_end(dt_end):
    
    dtend = datetime.strptime(dt_end,"%Y%m%dT%H%M%S")
    dtend = dtend.strftime(" e%I:%M %p:").replace("e0", " ").replace("e", "")
    return dtend


def processDate(x, date_start, until_event_date, startDate, endDate, dt_start, dt_end): 
    testcounter = 0
    while (date_start <= until_event_date):

        newStartDate = datetime.strptime(startDate, "%B %d, %Y (%a)" )
        newEndDate = datetime.strptime(endDate, "%B %d, %Y (%a)" )
        
        date_start = date_start + timedelta(days=7)

        if(date_start >= newStartDate and date_start <= newEndDate ):
            
            
            x['DTSTART'] = dt_start
            x['DTEND'] = dt_end
            actual_date = date_start.date()

            actual_date = actual_date.strftime("%B %d, %Y (%a)")
            x['ACTUAL_DATE'] = actual_date 
            actual_date = "tests"
            
            return x
        testcounter += 1
#this function filter the file that only necessary information remain. And return the filtered
#data contents
def filterDate(fileLine, startDate, endDate,input_start_day,input_start):
    i = 0
    filterList = []
    counter = 0
    
    
    for x in fileLine:
        
        dt_start = x["DTSTART"]
        dt_end = x["DTEND"]
        
        dtstart = datetime.strptime(dt_start,"%Y%m%dT%H%M%S")
        dtstart = dtstart.strftime("%B %d, %Y (%a)")
        

        x["DTSTART"]=dtstart
        
        x["DTEND"] = dateConvert_end(dt_end)
        dtstart_time = timeConvert_start(dt_start)
        
        dtend_time = timeConvert_end(dt_end)
        x["DTSTART_TIME"]=dtstart_time
        x["DTEND_TIME"]=dtend_time
        
        
        if not x.get('RRULE'):

        
            x["DTSTART"] = datetime.strptime(x["DTSTART"],"%B %d, %Y (%a)")
            startDate_datatime = datetime.strptime(startDate,"%B %d, %Y (%a)")
            endDate_datetime = datetime.strptime(endDate,"%B %d, %Y (%a)")
            x["DTEND"] = datetime.strptime(x["DTEND"],"%B %d, %Y (%a)")
            
            
            if x["DTSTART"] >= startDate_datatime and endDate_datetime >= x["DTEND"]:
                
                actual_date = x["DTSTART"].date()

                actual_date = actual_date.strftime("%B %d, %Y (%a)")
                x['ACTUAL_DATE'] = actual_date
                newx = x.copy() 
                filterList.append(x)



               
                
        else:
            #rrule1 is to hold the value of UNTIL date from RRULE line.
            rrule1 = x["RRULE"]
            rrule_split = rrule1[-24:]
            rrule_split = rrule_split.split(";")
            until = rrule_split[0]
            until = datetime.strptime(until, "%Y%m%dT%H%M%S")
            
            

        

        
        if "RRULE" in x:
            until_day = until + timedelta(days= 1)
            until_day = until_day.strftime("%a")
            
            until = until.strftime("%B %d, %Y (%a)")

            date_start = x['DTSTART']
            date_start = datetime.strptime(x['DTSTART'],"%B %d, %Y (%a)")
            actual_date = date_start.date()
            frequency = x['RRULE'].split(';')[0]
            until_event_date = x['RRULE'].split(';')[-2].split('=')[1]
            until_event_date = datetime.strptime(until_event_date, "%Y%m%dT%H%M%S")
            until_event_date = until_event_date 
            
            until_event_day = x['RRULE'].split(';')[2]

            
            
            testcounter = 0
            
            testlist = []
            
            while (date_start <= until_event_date):
                

                newStartDate = datetime.strptime(startDate, "%B %d, %Y (%a)" )
                newEndDate = datetime.strptime(endDate, "%B %d, %Y (%a)" )
                
                
                if(date_start >= newStartDate and date_start <= newEndDate  ):
                    
                    
                    x['DTSTART'] = dt_start
                    x['DTEND'] = dt_end
                    actual_date = date_start.date()

                    actual_date = actual_date.strftime("%B %d, %Y (%a)")
                

                    x['ACTUAL_DATE'] = actual_date
                    newx = x.copy() 
                    
                    filterList.append(newx)
                date_start = date_start + timedelta(days=7)
                    
    
    return filterList
#this function create the output of start time format
def printList_TIME_START(dt_start):
    
    dtstart = datetime.strptime(dt_start,"%Y%m%dT%H%M%S")
    dtstart = dtstart.strftime("e%I:%M %p to").replace("e0", " ").replace("e", "")
    return dtstart
#this function create the output of end time format
def printList_TIME_END(dt_end):
    
    dtend = datetime.strptime(dt_end,"%Y%m%dT%H%M%S")
    dtend = dtend.strftime(" e%I:%M %p:").replace(" e0", " ").replace("e", "")
    return dtend


def printListRRULE(filteredList, input_start,input_start_date,input_start_day,input_end,input_end_day,input_end_date):
    i = 0
    actual_dates = []
    for t in filteredList: 
        actual_dates.append(t['ACTUAL_DATE'])
    
    
    for t in list(dict.fromkeys(actual_dates)): 
        print(t)
        size = len(t)
        dashLine(size)
       
        filteredList = sorted( filteredList, key=lambda date: datetime.strptime(date['DTSTART_TIME'].replace(' ', ""), "%I:%M%pto"  ))
        
        for x in filteredList: 
            if t == x['ACTUAL_DATE']:

            
                print(x["DTSTART_TIME"], end = '')
                print(x["DTEND_TIME"], end = '')
                print(" "+ x["SUMMARY"], end = '')
                print(" {{" + x["LOCATION"] + "}}")

                
        if len(list(dict.fromkeys(actual_dates))) == 1: 
            pass
        elif i < len(list(dict.fromkeys(actual_dates)))-1:
            print()
            
        elif i == len(list(dict.fromkeys(actual_dates)))-1:
            pass
        i += 1
     

# this function printList print the output
def printList(filteredList, input_start,input_start_date,input_start_day,input_end,input_end_day,input_end_date):

    
    i=0
    for x in filteredList:
        
        #for those files not contain RRULE, execute in here
        if "RRULE" not in x:

            date = x["DTSTART"]
            date_end = x["DTEND"]

            date1 = date.strftime("%B %d, %Y (%a)")
            date2 = date_end.strftime("%B %d, %Y (%a)")
            
            print(date1)
            size = len(date1)
            dashLine(size)
            print(x["DTSTART_TIME"], end = '')
            print(x["DTEND_TIME"], end = '')
            print(" "+ x["SUMMARY"], end = '')
            print(" {{" + x["LOCATION"] + "}}")
            if len(filteredList) == 1: 
                
                pass
            elif i < len(filteredList)-1:
                print()
            elif i == len(filteredList)-1:
                pass
            i += 1
            continue
        # if content have RRULE then output is create in here
        else:

        
            print(x["ACTUAL_DATE"])
            temp = x["ACTUAL_DATE"]
            size = len(x["ACTUAL_DATE"])
            dashLine(size)
        
            print(x["DTSTART_TIME"], end = '')
            print(x["DTEND_TIME"], end = '')
            print(" "+ x["SUMMARY"], end = '')
            print(" {{" + x["LOCATION"] + "}}")

            
            if len(filteredList) == 1: 
                
                pass
            elif i < len(filteredList)-1:
                print()
            elif i == len(filteredList)-1:
                pass
            i += 1
            continue




def main():
    #create the input structure
    parser = argparse.ArgumentParser('put the input command')
    parser.add_argument('--start', dest="start", type=str, help='put start date')
    parser.add_argument('--end', dest="end", type=str, help='put end date')
    parser.add_argument('--file', dest="file", type=str, help='put ics file')
    args= parser.parse_args()
    
    input_start = datetime.strptime(args.start,"%Y/%m/%d")
    input_start_date = input_start.strftime("%B %d, %Y (%a)")
    input_start_day = input_start.strftime("%a")
    input_end = datetime.strptime(args.end,"%Y/%m/%d")
    input_end_date = input_end.strftime("%B %d, %Y (%a)")
    input_end_day = input_end.strftime("%a")
    

    #read the textfile 

    textFile = open(args.file, "r")

    fileLine = []
    event = {}
    counter = 0
    with textFile as f:

        i = 0
        for line in f:
            #creat dictionary
            if line == '\n':
                continue
            line = line.replace('\n', "")
            key = line.split(":")[0]
            value = line.split(":")[1]
            if line == "BEGIN:VEVENT" or counter == 1: 
                counter = 1
                event[key] = value 
                
            if line == "END:VEVENT": 
                counter = 0 
                fileLine.append(event)
                event = {} 
                

            i += 1 

        
    filteredList = filterDate(fileLine,input_start_date, input_end_date,input_start_day,input_start)
    
    filteredList = sorted( filteredList, key=lambda date: datetime.strptime(date['ACTUAL_DATE'], "%B %d, %Y (%a)"))
     
    printListRRULE(filteredList, input_start,input_start_date,input_start_day,input_end,input_end_day,input_end_date)
    
   

if __name__ == "__main__":
    main()

