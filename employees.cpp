#include <iostream>
#include<string>
#include<fstream>


int input() ; //to take N from user
void submit (int n) ;
std::string ID () ;
void search (std::string id) ;



struct employee {
	std::string name ;
	unsigned int age ;
	double wage ;
	std::string ID ;
};
  
int main() 
{ 

std::cout<<"do you want submit or search(su : submit , se : search ) ? " ;
std::string ask ;
std::cin>>ask ;
if(ask == "su"){
int n = input() ; // number of employees
submit(n) ; //to take and show information
}
else{
std::string id = ID () ;
search(id) ;
}
    
	return 0; 
}

//to take number of employees
int input(){

std::cout<<"enter  number of employees : " ;
int n ;
std::cin>>n ; 

return n ;
} 
 
//to submit information 
void submit (int n){
	
std::ofstream file ; 
file.open("information.txt" , std::ios::app) ; // you can replace information with any empty file
employee employees[n] ; //to save employees informations

if(file.is_open()) {
 

 
 //to take informations from user
for(int i = 0 ; i<n ; i++){
 	std::cout<<"enter employee's name : " ;
	std::cin.ignore();
 	std::getline(std::cin ,employees[i].name) ;
 	std::cout<<"enter employee's age : " ;
 	std::cin>>employees[i].age ;
 	std::cout<<"enter employee's wage : " ;
 	std::cin>>employees[i].wage ;
 	std::cout<<"enter employee's ID : " ;
 	std::cin>>employees[i].ID ;
 }
 //defined to submit information in file
bool flag = true ; // for breaking
for(int i = 0 ; i<n ;i++){
 	
	flag = true ;
	if(i == 0){
 	file<<"name : "<<employees[i].name<<" age : "<<employees[i].age<<" wage : "<<employees[i].wage<<" ID : "<<employees[i].ID<<std::endl ;
 	continue ;
    }
	for(int j = i-1 ; j>=0 ; j--){
	
	if(employees[i].ID == employees[j].ID){
	flag = false ; 
	break ; 
    }
    
	}
if(flag == false)
continue ;
else
file<<"name : "<<employees[i].name<<" age : "<<employees[i].age<<" wage : "<<employees[i].wage<<" ID : "<<employees[i].ID<<std::endl ;
}	
}
else
std::cerr <<"can't open the file"<< std::endl;

file.close() ;
			
}

// to take ID from user
std::string ID(){
std::cout<<"enter your ID : " ;
std::string id ;
std::cin>>id ;
return id ;
}

void search(std::string id){

std::ifstream file ; 
file.open("information.txt" , std::ios::in | std::ios::out) ; // you can replace information with any  file
std::string line ; //to save lines of file

if(file.is_open()){
int flag = true ;
int counter = 1 ;	
while(std::getline(file ,line))	{
	int found = line.find(id) ;
	if(found != -1){
	flag = false ;
	std::cout<<"user found in line "<<counter ;
	break ;
	}
	counter++ ;
}
	
if(flag == true)	
 std::cout<<"employee not found!" ;	
	
	
	
}
else
std::cerr <<"can't open the file"<< std::endl;

file.close() ;	
}
