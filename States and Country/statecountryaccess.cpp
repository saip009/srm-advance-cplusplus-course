/* Program to access country ,states and capital  from the excel database 

  content :source code(visual studio 2010),
		   database in excel,
		   NumberDuck (library for excel access).

  Authour: Sai praneeth (1031310381)
           Satyam verma (1031310411)*/


#include "NumberDuck.h"
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<conio.h>
using namespace NumberDuck;


int main(int argc, char **argv)
{
	int s,countryIndex=0,counMatch=0,stateMatch=0;
	char   country[50]={},searchCountry[50]={} ,state[50]={},searchState[50]={};
		Workbook* pWorkbookOutCountry = new Workbook("");
		pWorkbookOutCountry->Load("satyam(old).xls");
		Worksheet* pWorksheetOutCountry=pWorkbookOutCountry->GetWorksheetByIndex(countryIndex);
		std::cout<<"AVAILABLE COUNTRIES:"<<std::endl;
		Cell* countryCell;
			for(int iterator=0;iterator<10;iterator++){
					 countryCell=pWorksheetOutCountry->GetCell(0,iterator);
						 std::cout<<"\t"<<countryCell->GetString()<<std::endl;}
		restartCountry:
		countryIndex=0;
			printf("\n\nENTER THE COUNTRY:");
	//std::cin>>country;
			gets(country);
	
	
				while(countryIndex<10){
					  countryCell=pWorksheetOutCountry->GetCell(0,countryIndex);
	 // printf("%d\n",countryCell->GetType());
					  strcpy(searchCountry,countryCell->GetString());
	//  printf("%d\n",strcmp(country,searchCountry));
							if(!strcmp(country,searchCountry)){
	    //  cout<<"Matched"<<endl;
								  counMatch=1;	break; }
				countryIndex++;}
						if (counMatch==0){std::cout<<"NO MATCH...PLZ TRY AGAIN"<<std::endl; goto restartCountry;} 
	
		Workbook* pWorkbookOutState= new Workbook("");
		Worksheet* pWorksheetOutState;
		std::cout<<"STATES IN:";
		Cell* stateCell;
				for(int i=0;i<10;i++){
							if (pWorkbookOutState->Load("satyam(old).xls")){
									pWorksheetOutState = pWorkbookOutState->GetWorksheetByIndex(countryIndex+1);
									stateCell = pWorksheetOutState->GetCell(0,i); 
		//if(i==0){cout<<stateCell->GetString()<<endl; i++;}
									printf("%s\n\t", stateCell->GetString());}
				 // printf("%d\n",stateCell->GetType());
					}
		restartState:
		std::cout<<"\n\n\rENTER STATE:";
	//std::cin>>state;
		gets(state);

	//strcpy(searchState,state);
					for(int i=1;i<10;i++){
							if (pWorkbookOutState->Load("satyam(old).xls")){ 
										pWorksheetOutState = pWorkbookOutState->GetWorksheetByIndex(countryIndex+1);
										stateCell=pWorksheetOutState->GetCell(0,i);
										strcpy(searchState,stateCell->GetString());
												if(!strcmp(state,searchState)){
														stateCell=pWorksheetOutState->GetCell(1,i);
														std::cout<<"\nSTATE CAPITAL IS:";
														std::cout<<stateCell->GetString();
									         		    stateMatch=1;	break; }
         
								}
						}
	
		if(stateMatch==0){std::cout<<"NO MATCH...PLZ TRY AGAIN"<<std::endl; goto restartState;}
		std::cout<<"\n\nPPROGRAM TERMINATED SUCCESSFULLY !!!"<<std::endl;
		std::cout<<"\nPRESS ANY KEY TO  EXIT.";
		getch();
	//std::cin>>s;
	return 0;
}

