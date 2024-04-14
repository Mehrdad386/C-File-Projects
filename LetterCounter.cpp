#include<iostream> 
#include<fstream>
 
 
//this app get a letter from user and then it will check the given file to see how many times this word repeated
 
int main() { 


std::ifstream file ; //to check existence
file.open("tt.txt" ,std::ios::in | std::ios::out) ; //you can enter your own file here
char word ; // to take word from user
std::cin>>word ;
char fileWord ; //to check words one by one
int counter = 0 ; //to count number of given word

while(file.get(fileWord)){
	
	if(fileWord == word)
	counter++ ;
}
std::cout<<counter ;

file.close() ; // to close file

return 0; 
}