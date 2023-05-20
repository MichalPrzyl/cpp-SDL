#include<iostream>

using namespace std;


void change_variable_value(int &x){
	cout<<"change_variable_value function.\nChanging value to 69"<<endl;
	x = 69;
	cout<<"X value: "<<x<<endl;
}

int main(){
	int main_variable = 1;
	cout<<"In main function variable has value: "<<main_variable<<endl;


	// invoking change_variable_value function
	cout<<"Invoking change_variable_value function...\n"<<endl;
	change_variable_value(main_variable);
	cout<<"Variable value after invoking function: "<<main_variable<<endl;
		
}
