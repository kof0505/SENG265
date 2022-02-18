#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 132
#define MAX_EVENTS 500



void dt_format_case2(char *formatted_time, const char *dt_time, const int len)
{
    struct tm temp_time;
    time_t    full_time;
    char      temp[5];

    /*  
     * Ignore for now everything other than the year, month and date.
     * For conversion to work, months must be numbered from 0, and the 
     * year from 1900.
     */  
    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(dt_time, "%4d%2d%2d",
        &temp_time.tm_year, &temp_time.tm_mon, &temp_time.tm_mday);
    temp_time.tm_year -= 1900;
    temp_time.tm_mon -= 1;
    full_time = mktime(&temp_time);
    strftime(formatted_time, len, "%a", 
        localtime(&full_time));
        
}

void dt_format(char *formatted_time, const char *dt_time, const int len)
{
    struct tm temp_time;
    time_t    full_time;
    char      temp[5];

    /*  
     * Ignore for now everything other than the year, month and date.
     * For conversion to work, months must be numbered from 0, and the 
     * year from 1900.
     */  
    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(dt_time, "%4d%2d%2d",
        &temp_time.tm_year, &temp_time.tm_mon, &temp_time.tm_mday);
    temp_time.tm_year -= 1900;
    temp_time.tm_mon -= 1;
    full_time = mktime(&temp_time);
    strftime(formatted_time, len, "%B %d, %Y (%a)", 
        localtime(&full_time));
        
}

void start_time_format(char *formatted_time, const char *dt_time, const int len){

    struct tm temp_time;
    time_t    full_time;
    char      temp[5];

    /*  
     * Ignore for now everything other than the year, month and date.
     * For conversion to work, months must be numbered from 0, and the 
     * year from 1900.
     */  
    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(dt_time, "%2d%2d%2d",
    &temp_time.tm_hour , &temp_time.tm_min, &temp_time.tm_sec);
    
    full_time = mktime(&temp_time);
    
    int convert_begin_date_to_int1=atoi(temp);

    
    if( temp_time.tm_hour < 10 ){

        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour - 12 , &temp_time.tm_min, &temp_time.tm_sec);
        
        
        
        printf (" %d:",temp_time.tm_hour );

        strftime(formatted_time, len, "%M AM to ", 
        localtime(&full_time));

    }
    else if(10<=temp_time.tm_hour && temp_time.tm_hour < 12 ){

        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour - 12 , &temp_time.tm_min, &temp_time.tm_sec);
        
        
        
        printf ("%d:",temp_time.tm_hour );

        strftime(formatted_time, len, "%M AM to ", 
        localtime(&full_time));

    }

    else{
        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour , &temp_time.tm_min, &temp_time.tm_sec);
        if(temp_time.tm_hour==12){

        

        strftime(formatted_time, len, "%H:%M PM to ", 
        localtime(&full_time));

        
        }else{

            temp_time.tm_hour = temp_time.tm_hour - 12;
        
            printf (" %d:",temp_time.tm_hour );

            strftime(formatted_time, len, "%M PM to ", 
            localtime(&full_time));
        }

        
        

        
        
    }


}

void start_time_format1(char *formatted_time, const char *dt_time, const int len){

    struct tm temp_time;
    time_t    full_time;
    char      temp[5];

    /*  
     * Ignore for now everything other than the year, month and date.
     * For conversion to work, months must be numbered from 0, and the 
     * year from 1900.
     */  
    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(dt_time, "%2d%2d%2d",
    &temp_time.tm_hour , &temp_time.tm_min, &temp_time.tm_sec);
    
    full_time = mktime(&temp_time);
    
    int convert_begin_date_to_int1=atoi(temp);

    
    if( temp_time.tm_hour < 10 ){

        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour - 12 , &temp_time.tm_min, &temp_time.tm_sec);
        
        
        
        printf (" %d:",temp_time.tm_hour );

        strftime(formatted_time, len, "%M AM to", 
        localtime(&full_time));

    }
    else if(10<=temp_time.tm_hour && temp_time.tm_hour < 12 ){

        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour - 12 , &temp_time.tm_min, &temp_time.tm_sec);
        
        
        
        printf ("%d:",temp_time.tm_hour );

        strftime(formatted_time, len, "%M AM to", 
        localtime(&full_time));

    }

    else{
        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour , &temp_time.tm_min, &temp_time.tm_sec);
        if(temp_time.tm_hour==12){

        

        strftime(formatted_time, len, "%H:%M PM to ", 
        localtime(&full_time));

        
        }else{

            temp_time.tm_hour = temp_time.tm_hour - 12;
        
            printf (" %d:",temp_time.tm_hour );

            strftime(formatted_time, len, "%M PM to  ", 
            localtime(&full_time));
        }

        
        

        
        
    }


}


void end_time_format(char *formatted_time, const char *dt_time, const int len){

    struct tm temp_time;
    time_t    full_time;
    char      temp[5];

    /*  
     * Ignore for now everything other than the year, month and date.
     * For conversion to work, months must be numbered from 0, and the 
     * year from 1900.
     */  
    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(dt_time, "%2d%2d%2d",
    &temp_time.tm_hour, &temp_time.tm_min, &temp_time.tm_sec);
    
    full_time = mktime(&temp_time);
    
    

    if( temp_time.tm_hour < 12){

        strftime(formatted_time, len, " %H:%M AM:", 
        localtime(&full_time));
    }
    else{

        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour , &temp_time.tm_min, &temp_time.tm_sec);
        if(temp_time.tm_hour==12){

        

        strftime(formatted_time, len, "%H:%M PM:", 
        localtime(&full_time));
    
        }else{



            sscanf(dt_time, "%2d%2d%2d",
            &temp_time.tm_hour - 12 , &temp_time.tm_min, &temp_time.tm_sec);
        
            temp_time.tm_hour = temp_time.tm_hour - 12;
        
            printf (" %d:",temp_time.tm_hour );

            strftime(formatted_time, len, "%M PM:", 
            localtime(&full_time));
    }


}}
void end_time_format1(char *formatted_time, const char *dt_time, const int len){

    struct tm temp_time;
    time_t    full_time;
    char      temp[5];

    /*  
     * Ignore for now everything other than the year, month and date.
     * For conversion to work, months must be numbered from 0, and the 
     * year from 1900.
     */  
    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(dt_time, "%2d%2d%2d",
    &temp_time.tm_hour, &temp_time.tm_min, &temp_time.tm_sec);
    
    full_time = mktime(&temp_time);
    
    

    if( temp_time.tm_hour < 12){

        strftime(formatted_time, len, " %H:%M AM:", 
        localtime(&full_time));
    }
    else{

        sscanf(dt_time, "%2d%2d%2d",
        &temp_time.tm_hour , &temp_time.tm_min, &temp_time.tm_sec);
        if(temp_time.tm_hour==12){

        

        strftime(formatted_time, len, "%H:%M PM:", 
        localtime(&full_time));
    
        }else{



            sscanf(dt_time, "%2d%2d%2d",
            &temp_time.tm_hour - 12 , &temp_time.tm_min, &temp_time.tm_sec);
        
            temp_time.tm_hour = temp_time.tm_hour - 12;
        
            printf ("%d:",temp_time.tm_hour );

            strftime(formatted_time, len, "%M PM:", 
            localtime(&full_time));
    }


}}


void dt_increment(char *after, const char *before, int const num_days)
{
    struct tm temp_time, *p_temp_time;
    time_t    full_time;
    char      temp[5];

    memset(&temp_time, 0, sizeof(struct tm));
    sscanf(before, "%4d%2d%2dT%2d%2d%2d", &temp_time.tm_year,
        &temp_time.tm_mon, &temp_time.tm_mday, &temp_time.tm_hour, 
        &temp_time.tm_min, &temp_time.tm_sec);
    temp_time.tm_year -= 1900;
    temp_time.tm_mon -= 1;
    temp_time.tm_mday += num_days;

    full_time = mktime(&temp_time);
    after[0] = '\0';
    strftime(after, 16, "%Y%m%dT%H%M%S", localtime(&full_time));
    strncpy(after + 16, before + 16, MAX_LINE_LEN - 16); 
    after[MAX_LINE_LEN - 1] = '\0';
}
void type1(char *file){

    #define test 9
    #define test1 10
    #define test2 15
    char buffer_diff[MAX_LINE_LEN];
    char buffer[MAX_LINE_LEN];
    char buffer1[MAX_LINE_LEN];
    char buffer2[MAX_LINE_LEN];
    char test_2[test2];
    char *check;
    int count = 0;
    int total = 0;
    int case1;
    
    FILE *fp = fopen(file, "r");
    
    
    
      
    
    
    
        fseek(fp, 6, SEEK_CUR);
        fgets(buffer1, sizeof(buffer), fp);
        

        



        if(strstr(buffer1,"N:A") != NULL){

            fseek(fp, 6, SEEK_CUR);
            fgets(buffer1, sizeof(buffer), fp);


        }
        printf("%s\n\n\n",buffer1);
        fseek(fp, 6, SEEK_CUR);
        fgets(buffer1, sizeof(buffer), fp);
        if(strstr(buffer1, "VEVENT") != NULL){       

            char dtStart[MAX_LINE_LEN];
            char dtEnd[MAX_LINE_LEN];
            char RRULE[MAX_LINE_LEN];
            char LOCATION[MAX_LINE_LEN];
            char SUMMARY[MAX_LINE_LEN];
            char END_event[MAX_LINE_LEN];
            char END_calendar[MAX_LINE_LEN];
            char beginEvent[MAX_LINE_LEN];
            


            char freq[MAX_LINE_LEN];
            char weekstart[MAX_LINE_LEN];
            char date_until[MAX_LINE_LEN];
            char time_until[MAX_LINE_LEN];
            char byday[MAX_LINE_LEN];
            

            fseek(fp, 8, SEEK_CUR);
            fgets(buffer1, sizeof(buffer), fp);
            snprintf(dtStart,MAX_LINE_LEN,"%s",buffer1);
            

            long int cc = 0;
            char *startDate_array[MAX_LINE_LEN] = { NULL, };
            char *startDate = strtok(dtStart, "T");


            while (startDate != NULL){
                startDate_array[cc] = startDate;
                cc++;
                startDate = strtok(NULL,"T");
            }

            




            fseek(fp, 6, SEEK_CUR);
            fgets(buffer1, sizeof(buffer), fp);
            snprintf(dtEnd,MAX_LINE_LEN,"%s",buffer1);
            
            long int dd = 0;
            char *save_array02[MAX_LINE_LEN] = { NULL, };
            char *pointer2 = strtok(dtEnd, "T");


            while (pointer2 != NULL){
                save_array02[dd] = pointer2;
                dd++;
                pointer2 = strtok(NULL,"T");
            }

            

            

            fseek(fp, 9, SEEK_CUR);
            fgets(buffer1, sizeof(buffer), fp);
            snprintf(RRULE,MAX_LINE_LEN,"%s",buffer1);

            printf("sdfdsfdsfdsfds!!!!!!!!!!!!");

        
            if(strstr(RRULE, "BYDAY") != NULL){

                
                printf("sdfdsfdsfdsfds!!!!!!!!!!!!");

                    /* divide rrule line by ';'  */

                long int aa = 0;
                char *RRULE_array[MAX_LINE_LEN] = { NULL, };
                char *pointer = strtok(RRULE, ";");

            

                while (pointer != NULL){
                    RRULE_array[aa] = pointer;
                    aa++;
                    pointer = strtok(NULL,"; =");
                }
                printf("%s\n", RRULE_array[0]);
                printf("%s\n", RRULE_array[1]);
                printf("%s\n", RRULE_array[2]);
                printf("%s\n", RRULE_array[3]);
                printf("%s\n", RRULE_array[4]);
            


                fseek(fp, 9, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(LOCATION,MAX_LINE_LEN,"%s",buffer1);
            
                fseek(fp, 8, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(SUMMARY,MAX_LINE_LEN,"%s",buffer1);
            

                fseek(fp, 4, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(END_event,MAX_LINE_LEN,"%s",buffer1);
            

                
            
                SUMMARY[strcspn(SUMMARY, "\n")] = 0;
                LOCATION[strcspn(LOCATION, "\n")] = 0;

                int convert_dtStart_date_to_int1=atoi(dtStart);
            

                int convert_dtStart_date_to_int2=atoi(RRULE_array[4]);
            

                
            

                char itoa_start_date[MAX_LINE_LEN];
                char itoa_start_date1[MAX_LINE_LEN];
            
                
            
                char before_date[MAX_LINE_LEN];
                char after_date[MAX_LINE_LEN];
                char after_date1[MAX_LINE_LEN];
                char output_date[MAX_LINE_LEN];
                char output_date_increment[MAX_LINE_LEN];
                char output_date_time[MAX_LINE_LEN];
                char DAY_STORE[MAX_LINE_LEN];
                char DAY_STORE2[MAX_LINE_LEN];
                char DAY_STORE_char[MAX_LINE_LEN];
                char DAY_STORE2_char[MAX_LINE_LEN];
                char itoa_start_date_char[MAX_LINE_LEN];
                char itoa_start_date1_char[MAX_LINE_LEN];
                char DAY_STOREInLoop_char[MAX_LINE_LEN];
                char time_A[MAX_LINE_LEN];
                char output0[MAX_LINE_LEN];
                char output[MAX_LINE_LEN];

            
                

                
   
                end_time_format(output_date_time,save_array02[1],MAX_LINE_LEN);
                printf("%s",output_date_time);
                printf(" %s",SUMMARY);
                printf(" {{%s}}\n",LOCATION);
                        
                

                        


                }

                   
                
        }
          
    }


    

char* seperator(char text, char* text_array, char* seperator) {
    // while (startDate != NULL){
    //     save_array012[zz] = startDate;
    //     zz++;
    //     startDate = strtok(NULL,"T");
    // }
}
           
         
            
        


    


void print_events(int from_yy, int from_mm, int from_dd, 
    int to_yy, int to_mm, int to_dd, char *file)
{

    char buffer_diff[MAX_LINE_LEN];
    char buffer[MAX_LINE_LEN];
    char buffer1[MAX_LINE_LEN];
    char buffer2[MAX_LINE_LEN];
    char test_2[test2];
    char *check;
    int count = 0;
    int total = 0;
    int case1;
    int hhh =0;
    
    FILE *fp1 = fopen(file, "r");

    char choose1[MAX_LINE_LEN] = {0, };
    
    while (feof(fp1) == 0){
        if(feof(fp1)){

            
        
            goto here;
        } 
        fread(choose1, sizeof(MAX_LINE_LEN), MAX_LINE_LEN, fp1);    
                                 
                                 
        

    }
    FILE *fp = fopen(file, "r");
    
    
    here:
      
    
    // rrule with WKST include
    if(strstr(choose1, "WKST") != NULL){
        case1 = 1 ;
                
    }
    else{

        case1 = 2 ;
    }
    

    fseek(fp, 6, SEEK_CUR);
    fgets(buffer1, sizeof(buffer), fp);

    
    
    


 
   
    if(case1 == 2){
        int count2 = 0 ;

        


        if(strstr(buffer1, "VCALENDAR") != NULL){

           
            if(strstr(choose1, "FREQ") == NULL){
                
                there:
                there1:
                overhere:
                fseek(fp, 6, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);



                if(strstr(buffer1, "VEVENT") != NULL){
                    

                    char dtStart[MAX_LINE_LEN];
                    char dtEnd[MAX_LINE_LEN];
                    char LOCATION[MAX_LINE_LEN];
                    char SUMMARY[MAX_LINE_LEN];
                    char END_event[MAX_LINE_LEN];
                    char END_calendar[MAX_LINE_LEN];
                    fseek(fp, 8, SEEK_CUR);
                    fgets(buffer1, sizeof(buffer), fp);
                    snprintf(dtStart,MAX_LINE_LEN,"%s",buffer1);
                    
                    long int ff = 0;
                    char *startDate_array[MAX_LINE_LEN] = { NULL, };
                    char *startDate = strtok(dtStart, "T");



                    while (startDate != NULL){
                        startDate_array[ff] = startDate;
                        ff++;
                        startDate = strtok(NULL,"T");
                    }
                    
                    
                    fseek(fp, 6, SEEK_CUR);
                    fgets(buffer1, sizeof(buffer), fp);
                    snprintf(dtEnd,MAX_LINE_LEN,"%s",buffer1);

                    

                    long int dd = 0;
                    char *save_array02[MAX_LINE_LEN] = { NULL, };
                    char *pointer2 = strtok(dtEnd, "T");


                    while (pointer2 != NULL){
                        save_array02[dd] = pointer2;
                        dd++;
                        pointer2 = strtok(NULL,"T");
                    }

                
                    fseek(fp, 9, SEEK_CUR);
                    fgets(buffer1, sizeof(buffer), fp);
                    snprintf(LOCATION,MAX_LINE_LEN,"%s",buffer1);

                    
                    
        /////////////////////////////////////////START If There is RRULE /////////////////////////////////////////////////////////
                    if(strstr(buffer1, "BYDAY") != NULL){

                        

                        long int qq = 0;
                        char *RRULE_array[MAX_LINE_LEN] = { NULL, };
                        char *pointer = strtok(buffer1, ";");


                        while (pointer != NULL){
                            RRULE_array[qq] = pointer;
                            qq++;
                            pointer = strtok(NULL,"; =");
                        }

                    
                        long int zz = 0;
                        char *save_array012[MAX_LINE_LEN] = { NULL, };
                        char *startDate = strtok(RRULE_array[2], "T");


                        while (startDate != NULL){
                            save_array012[zz] = startDate;
                            zz++;
                            startDate = strtok(NULL,"T");
                        }

                        int fpLocation;
                        int fpLocation1;
                        
                        
                        //fgets(buffer1, sizeof(buffer), fp);
                       // fpLocation=ftell( fp );
                      //  printf("%d\n",fpLocation );

                        
                      //  printf("%s\n", buffer1);

                        
                       

                        
                    

                        fseek(fp, 9, SEEK_CUR);
                        fgets(buffer1, sizeof(buffer), fp);
                        snprintf(LOCATION,MAX_LINE_LEN,"%s",buffer1);
                       //printf("%s\n", buffer1);

                        if(strstr(buffer1, "210416T113000") != NULL){
                            fseek(fp, 9, SEEK_CUR);
                            fgets(buffer1, sizeof(buffer), fp);
                            
                            snprintf(LOCATION,MAX_LINE_LEN,"%s",buffer1);
                            
                            //fpLocation1=ftell( fp );
                            //printf("%dsfsdsdssdsdsdsds\n",fpLocation1 );
                        //  printf("%s\n", buffer1);
                        
                        
                        
                        }

                       
                        //fpLocation1=ftell( fp );
                        //printf("%d\n",fpLocation1 );


                       

                        fseek(fp, 8, SEEK_CUR);
                        fgets(buffer1, sizeof(buffer), fp);
                        snprintf(SUMMARY,MAX_LINE_LEN,"%s",buffer1);
                        

                        fseek(fp, 4, SEEK_CUR);
                        fgets(buffer1, sizeof(buffer), fp);
                        snprintf(END_event,MAX_LINE_LEN,"%s",buffer1);
                        

                       //fseek(fp, 4, SEEK_CUR);
                        //fgets(buffer1, sizeof(buffer), fp);
                        //snprintf(END_calendar,MAX_LINE_LEN,"%s",buffer1);

                        SUMMARY[strcspn(SUMMARY, "\n")] = 0;
                        LOCATION[strcspn(LOCATION, "\n")] = 0;
                    

                        int dianaDtEnd=atoi(dtEnd);
                        int dianaDtStart=atoi(dtStart);
                        int dianaUNTIL = atoi(save_array012[0]);

                        int intStartdate = atoi(save_array012[0]);

                        //printf("%d##########\n", dianaUNTIL);
                        int sample_begin_dateDiana = 10000*from_yy + 100*from_mm + from_dd;
                        int sample_end_dateDiana = 10000*to_yy + 100*to_mm + to_dd;

                        //printf("%d\n",sample_end_dateDiana);

                        char buf[MAX_LINE_LEN];
                

                        sprintf(buf,"%d",sample_begin_dateDiana);
                        
                        if(sample_begin_dateDiana <= dianaUNTIL){
////////////////////////////////////////////////////////////////////
                            if(sample_begin_dateDiana<=intStartdate){




                                char time_A[MAX_LINE_LEN];
                            char time_B[MAX_LINE_LEN];
                            char time_C[MAX_LINE_LEN];
                            char output0[MAX_LINE_LEN];
                            char output[MAX_LINE_LEN];
                            char output1[MAX_LINE_LEN];
                            char rrule_buffer[MAX_LINE_LEN];
                            char output_date_time[MAX_LINE_LEN];
                            char holdDay1[MAX_LINE_LEN];
                            char output11[MAX_LINE_LEN];
                            
                            char holdDay[MAX_LINE_LEN];
                            char dayFromat[MAX_LINE_LEN];

                          

                            

                            
                            
                            //printf("%s\n",RRULE_array[2]);

                            strncpy(holdDay1, buf, MAX_LINE_LEN);
                            dt_format_case2(output11, holdDay1, MAX_LINE_LEN);
                           //printf("%s\n\n\n\n", output11);

                            
                            strncpy(holdDay, startDate_array[0], MAX_LINE_LEN);


  



                            
                            
                            


                            dt_format_case2(output1, holdDay, MAX_LINE_LEN);
                           // printf("%s!!!!!!!!!!!!!!!!!!1\n\n\n\n", output1);

                            int compareDiana=strcmp(output11,output1);
                            //printf(" {{%s}}\n",LOCATION);

                             

                            //printf(" %d\n",compareDiana);
                        int asdf = 0; 
                        int lll =0;
                       
                         while(asdf< 100){
                                //printf("%s %s",output11,output1);
                            if(strstr(output11,output1) != NULL){

                                if(lll ==0){
                                

                                if(hhh == 0){

                               // printf("%s %s",output11,output1);
                               
                               strncpy(time_A, buf, MAX_LINE_LEN);
                            dt_format(output0, time_A, MAX_LINE_LEN);
                            
                            printf("%s\n", output0);

                            int print_number = 0;
                            while(print_number < strlen(output0)){

                                printf("-");
                                print_number++;
                            }
                             
                                printf("\n");
                                start_time_format1(output, startDate_array[1], MAX_LINE_LEN);
                                printf("%s", output);

                                end_time_format1(output_date_time,save_array02[1],MAX_LINE_LEN);
                                printf("%s",output_date_time);
                                printf(" %s",SUMMARY);
                                printf(" {{%s}}\n",LOCATION);
                                //printf(" \n");
                                hhh++;
                            }
                            else{

                                 
                                start_time_format1(output, startDate_array[1], MAX_LINE_LEN);
                                printf("%s", output);

                                end_time_format1(output_date_time,save_array02[1],MAX_LINE_LEN);
                                printf("%s",output_date_time);
                                printf(" %s",SUMMARY);
                                printf(" {{%s}}\n",LOCATION);
                                
                                hhh++;


                            }
                            
                            }
                            else{



                            strncpy(time_A, buf, MAX_LINE_LEN);
                            dt_format(output0, time_A, MAX_LINE_LEN);
                            
                            printf("%s\n", output0);

                            int print_number = 0;
                            while(print_number < strlen(output0)){

                                printf("-");
                                print_number++;
                            }
                             
                                printf("\n");

                                




                            }
                            }
                            
                            asdf++;
                            
                            
                            goto overhere;
                            }

                            










                            }
//////////////////////////////////////////////////////////////////////////////////////////////////
                           
/*
                            char time_A[MAX_LINE_LEN];
                            char time_B[MAX_LINE_LEN];
                            char time_C[MAX_LINE_LEN];
                            char output0[MAX_LINE_LEN];
                            char output[MAX_LINE_LEN];
                            char output1[MAX_LINE_LEN];
                            char rrule_buffer[MAX_LINE_LEN];
                            char output_date_time[MAX_LINE_LEN];
                            char holdDay1[MAX_LINE_LEN];
                            char output11[MAX_LINE_LEN];
                            
                            char holdDay[MAX_LINE_LEN];
                            char dayFromat[MAX_LINE_LEN];

                          

                            

                            
                            
                            //printf("%s\n",RRULE_array[2]);

                            strncpy(holdDay1, buf, MAX_LINE_LEN);
                            dt_format_case2(output11, holdDay1, MAX_LINE_LEN);
                           //printf("%s\n\n\n\n", output11);

                            
                            strncpy(holdDay, startDate_array[0], MAX_LINE_LEN);


  



                            
                            
                            


                            dt_format_case2(output1, holdDay, MAX_LINE_LEN);
                           // printf("%s!!!!!!!!!!!!!!!!!!1\n\n\n\n", output1);

                            int compareDiana=strcmp(output11,output1);
                            //printf(" {{%s}}\n",LOCATION);

                             

                            //printf(" %d\n",compareDiana);
                        int asdf = 0; 
                       
                         while(asdf< 100){
                                //printf("%s %s",output11,output1);
                            if(strstr(output11,output1) != NULL){
                                

                                if(hhh == 0){

                               // printf("%s %s",output11,output1);
                               strncpy(time_A, buf, MAX_LINE_LEN);
                            dt_format(output0, time_A, MAX_LINE_LEN);
                            
                            printf("%s\n", output0);

                            int print_number = 0;
                            while(print_number < strlen(output0)){

                                printf("-");
                                print_number++;
                            }
                             
                                printf("\n");
                                start_time_format1(output, startDate_array[1], MAX_LINE_LEN);
                                printf("%s", output);

                                end_time_format1(output_date_time,save_array02[1],MAX_LINE_LEN);
                                printf("%s",output_date_time);
                                printf(" %s",SUMMARY);
                                printf(" {{%s}}\n",LOCATION);
                                //printf(" \n");
                                hhh++;
                            }
                            else{

                                 
                                start_time_format1(output, startDate_array[1], MAX_LINE_LEN);
                                printf("%s", output);

                                end_time_format1(output_date_time,save_array02[1],MAX_LINE_LEN);
                                printf("%s",output_date_time);
                                printf(" %s",SUMMARY);
                                printf(" {{%s}}\n",LOCATION);
                                
                                hhh++;


                            }
                            
                            }
                            
                            asdf++;
                            
                            
                            goto overhere;
                            }

                            printf("out of while loop !!!!\n");

                            fgets(buffer1, sizeof(buffer), fp);
                                

                            fclose(fp);

                            if(strstr(buffer1,"VEVENT")!= NULL){

                                //fgets(buffer1, sizeof(buffer), fp);   
                                    
                                //printf("dsfdsfdsfsdfdsfsdgag");    
                                fseek(fp, -13, SEEK_CUR);

                                
                                    

                                fclose(fp);    
                                goto there1;

                            }
                            fclose(fp);

                            */
                        
                            
                        }
                        
                    }

        //////////////////////////////////////////END If there is RRULE  ////////////////////////////////////////////////////////  
                    


                    fseek(fp, 8, SEEK_CUR);
                    fgets(buffer1, sizeof(buffer), fp);
                    snprintf(SUMMARY,MAX_LINE_LEN,"%s",buffer1);
                    

                    fseek(fp, 4, SEEK_CUR);
                    fgets(buffer1, sizeof(buffer), fp);
                    snprintf(END_event,MAX_LINE_LEN,"%s",buffer1);
                    

                    fseek(fp, 4, SEEK_CUR);
                    fgets(buffer1, sizeof(buffer), fp);
                    snprintf(END_calendar,MAX_LINE_LEN,"%s",buffer1);

                    /* source: https://stackoverflow.com/questions/269377
                        6/removing-trailing-newline-character-from-fgets-input
                        
                        31
                        This even handles the rare buffer than begins with '\0', 
                        something that causes grief for the
                        buffer[strlen(buffer) - 1] = '\0'; approach. – 
                        chux - Reinstate Monica
                        Feb 11 '15 at 19:39 
                        
                        */

                    SUMMARY[strcspn(SUMMARY, "\n")] = 0;
                    LOCATION[strcspn(LOCATION, "\n")] = 0;
                

                    int convert_begin_date_to_int=atoi(dtEnd);
                    int convert_begin_date_to_int1=atoi(buffer2);
                    int sample_begin_date = 10000*from_yy + 100*from_mm + from_dd;

                    
                    if(sample_begin_date <= convert_begin_date_to_int){

                        char time_A[MAX_LINE_LEN];
                        char time_B[MAX_LINE_LEN];
                        char time_C[MAX_LINE_LEN];
                        char output0[MAX_LINE_LEN];
                        char output[MAX_LINE_LEN];
                        char output1[MAX_LINE_LEN];
                        char rrule_buffer[MAX_LINE_LEN];
                        char output_date_time[MAX_LINE_LEN];
                        

                        if (count2 == 0) {
                            count2++;
                        }
                        else if (count2 == 1)  {
                            printf("\n"); 
                        }

                        strncpy(time_A, dtStart, MAX_LINE_LEN);
                        dt_format(output0, time_A, MAX_LINE_LEN);
                        
                        printf("%s\n", output0);

                        int print_number = 0;
                        while(print_number < strlen(output0)){

                            printf("-");
                            print_number++;
                        }
                        printf("\n");
                        start_time_format(output, startDate_array[1], MAX_LINE_LEN);
                        printf("%s", output);

                        end_time_format(output_date_time,save_array02[1],MAX_LINE_LEN);
                        printf("%s",output_date_time);
                        printf(" %s",SUMMARY);
                        printf(" {{%s}}\n",LOCATION);
                        //printf(" \n");
                        

                    

                        if(strstr(END_event,"VEVENT")!= NULL){

                            
                            
                            
                            fseek(fp, -13, SEEK_CUR);
                            


                            goto there;
                            
                        }else{
                            goto loop1;

                        }

                        

                        
                    } 
                    
                    
                    loop1:
                    
                    fclose(fp);
                }
            

            
            
            }
                
                
            
                
        }


    }
      

      
    if(case1 == 1){
    
        if(strstr(buffer1, "VCALENDAR") != NULL){
        
        
            
            jumpj:
            fseek(fp, 6, SEEK_CUR);
            fgets(buffer1, sizeof(buffer), fp);



            if(strstr(buffer1,"N:A") != NULL){

                fseek(fp, 6, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);


            }

            if(strstr(buffer1, "VEVENT") != NULL){       

                char dtStart[MAX_LINE_LEN];
                char dtEnd[MAX_LINE_LEN];
                char RRULE[MAX_LINE_LEN];
                char LOCATION[MAX_LINE_LEN];
                char SUMMARY[MAX_LINE_LEN];
                char END_event[MAX_LINE_LEN];
                char END_calendar[MAX_LINE_LEN];


                char freq[MAX_LINE_LEN];
                char weekstart[MAX_LINE_LEN];
                char date_until[MAX_LINE_LEN];
                char time_until[MAX_LINE_LEN];
                char byday[MAX_LINE_LEN];

                fseek(fp, 8, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(dtStart,MAX_LINE_LEN,"%s",buffer1);


                long int cc = 0;
                char *startDate_array[MAX_LINE_LEN] = { NULL, };
                char *startDate = strtok(dtStart, "T");


                while (startDate != NULL){
                    startDate_array[cc] = startDate;
                    cc++;
                    startDate = strtok(NULL,"T");
                }

                




                fseek(fp, 6, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(dtEnd,MAX_LINE_LEN,"%s",buffer1);
                
                long int dd = 0;
                char *save_array02[MAX_LINE_LEN] = { NULL, };
                char *pointer2 = strtok(dtEnd, "T");


                while (pointer2 != NULL){
                    save_array02[dd] = pointer2;
                    dd++;
                    pointer2 = strtok(NULL,"T");
                }

                

                

                

                fseek(fp, 11, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(RRULE,MAX_LINE_LEN,"%s",buffer1);
                

                /* divide rrule line by '; ='  */

                long int aa = 0;
                char *RRULE_array[MAX_LINE_LEN] = { NULL, };
                char *pointer = strtok(RRULE, ";");


                while (pointer != NULL){
                    RRULE_array[aa] = pointer;
                    aa++;
                    pointer = strtok(NULL,"; =");
                }
                
                


                fseek(fp, 9, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(LOCATION,MAX_LINE_LEN,"%s",buffer1);
                
                fseek(fp, 8, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(SUMMARY,MAX_LINE_LEN,"%s",buffer1);
                

                fseek(fp, 4, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(END_event,MAX_LINE_LEN,"%s",buffer1);
                

                fseek(fp, 4, SEEK_CUR);
                fgets(buffer1, sizeof(buffer), fp);
                snprintf(END_calendar,MAX_LINE_LEN,"%s",buffer1);
                
                SUMMARY[strcspn(SUMMARY, "\n")] = 0;
                LOCATION[strcspn(LOCATION, "\n")] = 0;

                int convert_dtStart_date_to_int1=atoi(dtStart);
                

                int convert_dtStart_date_to_int2=atoi(RRULE_array[4]);
                

                int sample_begin_date1 = 10000*from_yy + 100*from_mm + from_dd;
                int sample_to_date11 = 10000*to_yy + 100*to_mm + to_dd;
                

                char itoa_start_date[MAX_LINE_LEN];
                char itoa_start_date1[MAX_LINE_LEN];
                
                sprintf(itoa_start_date,"%d",sample_begin_date1);
                
                sprintf(itoa_start_date1,"%d",sample_to_date11);
                
                char before_date[MAX_LINE_LEN];
                char after_date[MAX_LINE_LEN];
                char after_date1[MAX_LINE_LEN];
                char output_date[MAX_LINE_LEN];
                char output_date_increment[MAX_LINE_LEN];
                char output_date_time[MAX_LINE_LEN];
                char DAY_STORE[MAX_LINE_LEN];
                char DAY_STORE2[MAX_LINE_LEN];
                char DAY_STORE_char[MAX_LINE_LEN];
                char DAY_STORE2_char[MAX_LINE_LEN];
                char itoa_start_date_char[MAX_LINE_LEN];
                char itoa_start_date1_char[MAX_LINE_LEN];
                char DAY_STOREInLoop_char[MAX_LINE_LEN];

                
                dt_format_case2(DAY_STORE,itoa_start_date,MAX_LINE_LEN);
            

                if(convert_dtStart_date_to_int1 <= sample_begin_date1){

                    if(sample_begin_date1 <= convert_dtStart_date_to_int2){
        
                    
                        dt_format(itoa_start_date_char,itoa_start_date,MAX_LINE_LEN);
                        dt_format(itoa_start_date1_char,itoa_start_date1,MAX_LINE_LEN);

                        dt_increment(after_date, itoa_start_date, 0);
                        dt_increment(after_date1, itoa_start_date1, 0);
                        
                        dt_format_case2(output_date, after_date, MAX_LINE_LEN);
                    
                        int convert_after_date1_to_int=atoi(after_date1);
                        int convert_after_date_to_int=atoi(after_date);
                        
                        int asdf =0 ;
                        int count = 0;
                    while(convert_after_date_to_int != convert_after_date1_to_int){

                        while( asdf  < 365){
                                dt_format_case2(DAY_STOREInLoop_char,dtStart,MAX_LINE_LEN);

                                
                                dt_increment(after_date, after_date, 1);
                                dt_format_case2(DAY_STORE,after_date,MAX_LINE_LEN);

                                int convert_after_date_to_int=atoi(after_date);
                                int convert_after_date1_to_int=atoi(after_date1);
                                int print_number1=0;
                                
                                if(strcmp(DAY_STORE ,DAY_STOREInLoop_char)==0){
                                    if (count == 0) {
                                        count++;
                                    }
                                    else if (count == 1) {
                                       printf("\n"); 
                                    }
                                    dt_format(output_date_increment, after_date, MAX_LINE_LEN);
                                    printf("%s\n",output_date_increment);
                                    while( print_number1 < strlen(output_date_increment)){

                                    printf("-");
                                    print_number1++;
                                
                                    }
                                    printf("\n");
                                    start_time_format(output_date_time, startDate_array[1], MAX_LINE_LEN);
                                    printf("%s",output_date_time);
                                    
                                    end_time_format(output_date_time,save_array02[1],MAX_LINE_LEN);
                                    printf("%s",output_date_time);
                                    printf(" %s",SUMMARY);
                                    printf(" {{%s}}\n",LOCATION);
                                
                                }

                            if(convert_after_date_to_int == convert_after_date1_to_int){
                                    int convert_after_date_to_int=atoi(after_date);
                                    int convert_after_date1_to_int=atoi(after_date1);
                                    //printf("\n" );
                                    break;
                            }   
                                asdf += 1 ;
                        }
                            break;    
                    }
                        


                    }


                }


                if(strstr(END_event,"VEVENT")!= NULL){

                    goto jumpj;
        
                    
                }
                
                
                fclose(fp);
                
            
            }
            

        }
    }
               
}
    
    
   
    



int main(int argc, char *argv[])
{
    int from_y = 0, from_m = 0, from_d = 0;
    int to_y = 0, to_m = 0, to_d = 0;
    char *filename = NULL;
    int i; 

    for (i = 0; i < argc; i++) {
        if (strncmp(argv[i], "--start=", 8) == 0) {
            sscanf(argv[i], "--start=%d/%d/%d", &from_y, &from_m, &from_d);
        } else if (strncmp(argv[i], "--end=", 6) == 0) {
            sscanf(argv[i], "--end=%d/%d/%d", &to_y, &to_m, &to_d);
        } else if (strncmp(argv[i], "--file=", 7) == 0) {
            filename = argv[i]+7;
        }
    }

    if (from_y == 0 || to_y == 0 || filename == NULL) {
        fprintf(stderr, 
            "usage: %s --start=yyyy/mm/dd --end=yyyy/mm/dd --file=icsfile\n",
            argv[0]);
        exit(1);
    }

    /* Starting calling your own code from this point. */
    print_events(from_y, from_m, from_d, 
    to_y, to_m, to_d,filename);
    

    exit(0);
}