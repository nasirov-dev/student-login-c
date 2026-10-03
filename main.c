#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct{
	
	char name[100];
	//
	int ID;
	//
	char surname[100];
	//
	int password;
	//
	int age;
	//
    int grades[3];
    
} Data;



void sound(void){
	
	
	Beep(600, 500);
	Beep(500, 500);
	Beep(400, 500);
}

int login(Data students[], int count, int id, int password){


    for (int i = 0; i < count; i++)
    {
        if (students[i].ID == id && students[i].password == password)
        {
            return i;
        }
    }
    return -1;
} 

int readInt(const char *word, int *value){
    printf("%s", word);

    if (scanf("%d", value) != 1){
        int clean;
        while ((clean = getchar()) != '\n' && c != EOF);
        return 0;  
    }
    return 1;       
}


int main(void){
	
	
	
	Data students[25] = {
    {"Murad",   291291, "Nasirov",    200829, 17, {100, 100, 100}},
    {"Nurlan",   291292, "Mammadov",  299912, 18, {75, 80, 95}},
    {"Aysel",   291293, "Hasanova",   123456, 17, {100, 90, 85}},
    {"Kamran",  291294, "Huseynov",   458213, 18, {68, 74, 81}},
    {"Leyla",   291295, "Ismayilova", 731904, 17, {92, 88, 95}},
    {"Rauf",    291296, "Guliyev",    284617, 19, {55, 62, 70}},
    {"Nigar",   291297, "Rzayeva",    946320, 16, {87, 91, 79}},
    {"Tural",   291298, "Abbasov",    122312, 18, {73, 66, 80}},
    {"Sevinc",  291299, "Mustafayeva",367095, 17, {96, 98, 93}},
    {"Orxan",   291300, "Jafarov",    820416, 18, {60, 58, 72}},
    {"Gunel",   291301, "Aslanova",   159783, 17, {84, 79, 88}},
    {"Farid",   291302, "Safarov",    604871, 19, {77, 85, 69}},
    {"Aynur",   291303, "Valiyeva",   392058, 16, {91, 94, 89}},
    {"Emin",    291304, "Karimov",    715264, 18, {65, 70, 63}},
    {"Narmin",  291305, "Bagirova",   248931, 17, {99, 97, 100}},
    {"Samir",   291306, "Najafov",    873602, 18, {71, 76, 82}},
    {"Fidan",   291307, "Orucova",    536147, 17, {88, 83, 90}},
    {"Vugar",   291308, "Mehdiyev",   402689, 19, {57, 64, 59}},
    {"Lale",    291309, "Qasimova",   918375, 16, {94, 89, 92}},
    {"Ilkin",   291310, "Rahimov",    667024, 18, {79, 81, 74}},
    {"Zaur",    291311, "Taghiyev",   135496, 17, {83, 77, 86}},
    {"Sabina",  291312, "Ahmadova",   790258, 18, {90, 95, 87}},
    {"Cavid",   291313, "Namazov",    321840, 19, {62, 68, 75}},
    {"Aytac",   291314, "Hajiyeva",   584716, 17, {85, 92, 88}},
    {"Resad",   291315, "Ibrahimov",  476923, 18, {72, 69, 78}}
};
	int inputID, inputPassword;
	
	
	int found = 0;
    
    int attempt = 3;
    int count = sizeof(students) / sizeof(students[0]);
    
    
while(attempt > 0 && found == 0){
	
	
    
    if (!readInt("Please enter your ID: ", &inputID) || !readInt("Please enter your password: ", &inputPassword)){
    
    	
    printf("\nInvalid input! Numbers only.\n");
    
    attempt--;
    if (attempt == 0){
    	
    printf("\nAccess Denied.\n");
    
    }
    continue;
  }

  


    int index = login(students, count, inputID, inputPassword);
    	
    	
    	
    	
    	if (index != -1){
    		
    		
    		
    		printf("\nPlease wait a bit...\n");
    	    Sleep(2000);
    		
    		printf("Welcome %s!\n", students[index].name);
    		
    		sound();
    		for (int j = 0; j < 3; j++){
    			
    			
    			printf("Grade %d: %d\n", j + 1, students[index].grades[j]);
			}
    		found = 1;
    		
		}
		
       
        
        
        if (found == 0){
           printf("\nPlease wait a bit...\n");
           Sleep(2000);
           
           attempt--;
           
	 
	 
	     if (attempt == 0){
	   	 
	   	  printf("\nAccess Denied.\n");
	     } else {
	   	
	   	 printf("Wrong ID or Password! Attempts left: %d\n", attempt);
	   } 
    }
}
	return 0;
}
 


