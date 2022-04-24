
/*Name : Mahesh Ramdas Dubal 
  Class : MSC IMCA 2nd Year(Industrial Mathematics With Computer Applications)
  Question : Accept amount from user and print it in words.
e.g. 156,276,232 is One Hundred Fifty Six Million Two Hundred Seventy Six Thousand ,Two Hundred Thirty Two

  1000 - Thousand
  10,000 - Ten Thousand
  100,000 - Hundred Thousand
  1,000,000 - Million
  10,000,000 - Ten Million
  100,000,000 - Hundred Million
  1,000,000,000 - Bilion
  10,000,000,000 - Ten Bilion
  100,000,000,000 - Hundred Bilion
  1,000,000,000,000 -Trillion
  10,000,000,000,000 -Ten Trillion
  100,000,000,000,000 - Hundred Trillion
  1,000,000,000,000,000 - Quadrillion
  10,000,000,000,000,000 - Ten Quadrillion
  100,000,000,000,000,000 - Hundred Quadrillion
  ......
  ........
  .........
  */
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
char str[100];

void end_word(int n)
{
	switch(n)
	{
		case 1:cout<<" ";
			break;
		case 2:cout<<"Thousand ";
			break;
		case 3:cout<<"Million ";
			break;
		case 4:cout<<"Bilion ";
			break;
		case 5:cout<<"Trillion ";
			break;
		case 6:cout<<"Quadrillion ";
			break;
		case 7:cout<<"Quintillion ";
			break;
		case 8:cout<<"Hextillion ";
			break;
		case 9:cout<<"Septillion ";
			break;
		case 10:cout<<"Octillion ";
			break;
		case 11:cout<<"Nonillion ";
			break;
		case 12:cout<<"Decillion ";
			break;
	}
}
void single_digit(char ch)
{
	switch(ch)
	{
		case '0' : cout<<"";break;
		case '1' : cout<<"One ";break;
		case '2' : cout<<"Two ";break;
		case '3' : cout<<"Three ";break;
		case '4' : cout<<"Four ";break;
		case '5' : cout<<"Five ";break;
		case '6' : cout<<"Six ";break;
		case '7' : cout<<"Seven ";break;
		case '8' : cout<<"Eight ";break;
		case '9' : cout<<"Nine ";
	}
}

void num_to_words(char ch3,char ch2,char ch1)  //ch3 - 100'th place ,ch2 - 10th place and ch1- Unit place digit in bucket
{
	if(ch3 == '0')
	{
		cout<<"";
	}
	else if(ch3 != '0')  //e.g.121
	{
		single_digit(ch3);
		cout<<"Hundred ";
	}
	
	if(ch2 == '0' && ch1 == '0')
	{
		cout<<"";
	}
	else if(ch2 == '0' && ch1 != '0') //e.g.102
	{
		single_digit(ch1); 
	}
	else if(ch2 == '1')   //e.g.10,11,12,...
	{
		switch(ch1)
		{
			case '0' : cout<<"Ten ";break;
			case '1' : cout<<"Eleven ";break;
			case '2' : cout<<"Twelve ";break;
			case '3' : cout<<"Thirteen ";break;
			case '4' : cout<<"Fourteen ";break;
			case '5' : cout<<"Fifteen ";break;
			case '6' : cout<<"Sixteen ";break;
			case '7' : cout<<"Seventeen ";break;
			case '8' : cout<<"Eighteen ";break;
			case '9' : cout<<"Nineteen ";
		}
	}
	else if(ch2 != '0') //e.g 120
	{
		switch(ch2) 
		{
			case '2' : cout<<"Twenty ";break;
			case '3' : cout<<"Thirty ";break;
			case '4' : cout<<"Forty ";break;
			case '5' : cout<<"Fifty ";break;
			case '6' : cout<<"Sixty ";break;
			case '7' : cout<<"Seventy ";break;
			case '8' : cout<<"Eighty ";break;
			case '9' : cout<<"Ninty ";
		}
		single_digit(ch1); //For unit place
	}	
}

int main()
{
	
	bool invalid = false;
	int flag = 0;
	float s,len;
	int choice;
	
	//To accept proper number(for valid input)
	while(invalid == false)
	{
		cout<<"Enter Your Amount : ";
		cin>>str;
		int length = strlen(str);
		
		for(int i = 0; i < length; i++)
		{
			if(str[i]>='0' && str[i]<='9')
			{
				flag = 1;
			}	
			else
			{
				flag = 0;
			}
		}
		if(flag==1 && length < 34) //Decillion have 34 zero's
		{
			invalid = true;
		}
		else
		{
			cout<<"Invalid Input !!!"<<endl;
			invalid = false;	
		}
	}
	
	len = strlen(str);  //length of given string
	s = ceil(len/3); //number of buckets required ,ceil gives 3 for 2.5 i.e. just next integer value of fraction

	int k = s*3;  //new array size which is multiple of 3
	char new_str[k]; //defining new array to make all buckets of size 3
	
	for(int i = 0; i<k ;i++) //Initializing new array with zero
	{
		new_str[i] = '0';
	}
	
	if((int)len%3 == 2)  //e.g number is 11 digit so 11%3 = 2
	{
		for(int i = 0; i<k;i++)
		{
			new_str[i+1] = str[i];
		}
	}
	else if((int)len%3 == 1) //e.g number is 10 digit so 10%3 = 1
	{
		for(int i = 0; i<k;i++)
		{
			new_str[i+2] = str[i];
		}
	}
	else if((int)len%3 == 0)  //e.g.Number is multiple of 3 i.e. 12%3 = 0
	{
		for(int i = 0; i<k;i++)
		{
			new_str[i] = str[i];
		}
	}

	int j = 0;
	while(s>0)
	{
		num_to_words(new_str[j],new_str[j+1],new_str[j+2]);
		if((new_str[j]== '0')&& (new_str[j+1] == '0') &&(new_str[j+2])=='0')
		{
			cout<<""; //To skip unnecessary Million ,Hundred words e.g. 1000000 is One Million not One Million Hundred
		}
		else
		{
			end_word(s);
		}
		 //To print Million,Billion,...etc
		j = j+3; //To pass next 3 parameters to function
		s--; //Decrementing bucket number
	}	
		
	return 0;
}
