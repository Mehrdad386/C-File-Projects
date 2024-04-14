#include<iostream> 
#include<fstream>
#include<string>
#include<sstream>

struct info {
	std::string number ; //student's number
	std::string pass ; //student's password
};

std::string intToString(int num) ; // to change pass type from int to string
int stringToInt(std::string txt) ; // to change grade type from string to int
info LogIn() ; //for logging in
void searchPin(info login) ;  //to look for information in pin file
void searchInfo(std::string number) ; //to look for information in info file



 
int main() {  

info login = LogIn() ;
searchPin(login) ;

return 0; 
}


info LogIn(){
	
info login ;
int pass ;
std::cout<<"enter your student's number : " ;
std::cin>>login.number ;
std::cout<<"enter your password : " ;
std::cin>>pass ;
login.pass = intToString(pass*3/5) ;

return login ;
	
}






void searchPin (info log) {

info login = log ;
std::ifstream file ;
file.open("pin.txt" , std::ios::in | std::ios::out)	;
std::string line ;
bool flag = true ;
if(file.is_open()){

while(std::getline(file ,line)){

int checkn = line.find(login.number) ; //to check student number
int checkp = line.find(login.pass) ; //to check password


if(checkn != std::string::npos && checkp != std::string::npos){
	flag = false ;
	
	std::istringstream part(line) ;
	std::string word ;
	
	int counter =1 ; //to stop loop from showing pass
	while(part>>word){
	if(counter<3)
		std::cout<<word<<'\t' ;
		
	counter++ ;
	}	
	std::cout<<'\n' ;
	searchInfo(login.number) ;
	break ;
}

}
if(flag == true){
	std::cout<<" incorrect number or password " ;
	
}
}
else
std::cerr<<"can't open the file"<<std::endl ;

}






void searchInfo (std::string number){

std::ifstream file ;
file.open("info.txt" , std::ios::in | std::ios::out) ;
std::string line ;
int passed = 0 ;
int failed = 0 ;
int total = 0 ; //for average

if(file.is_open()){

while(std::getline(file , line)){
	int check = line.find(number) ;
	if(check != -1){
	std::cout<<line<<std::endl ;
	
	std::stringstream part(line) ;
	std::string grade;
    int counter = 0 ; //the third word is grade so we need it
	while(part>>grade){
		counter++ ;
		if(counter == 3){
		int point = stringToInt(grade) ;
		total += point ;
		if(point >= 10)
		passed++ ;
		else
		failed++ ;
	}
	}
    }
}
std::cout<<"passed : "<<passed<<std::endl ;
std::cout<<"failed : "<<failed<<std::endl ;
std::cout<<"average : "<< total/3<<std::endl ;

}
else
std::cerr<<"can't open the file"<<std::endl ;
	
}






std::string intToString(int num) {
    if (num == 0)
        return "0";
        
    std::string pass = "";
    
    while (num != 0) {
        int digit = num % 10;
        char c = '0' + digit;
        pass = c + pass;
        num /= 10;
    }
    
    return pass;
}




int stringToInt(std::string txt){
	int grade = 0 ;
	for(int i = 0 ; i<txt.size() ; i++){
		if(isdigit(txt[i]))
		   grade = grade*10 +(txt[i] - '0') ;
		   else{
		   std::cerr<<"invalid" ;
		   return 0 ;
	}
	
	}
	return grade ;
}


