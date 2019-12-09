#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	char *p;
	node* next = NULL;
};

class stringBuilder
{
public:
	node* newst;
	node* head;
	node* tail;
	//char** newstarr;
	stringBuilder(char* tempch)
	{
//		cout<<"temp "<<tempch<<endl;
		node* temp = new node();
		temp->p = tempch;
		temp->next = NULL;
//		cout<<"here"<<endl;
//		newst->next = NULL;		
		newst = temp;	
		head = temp;
		tail = temp;
			
	}
	
	char* toString()
	{
		int count = 0;
		char *concatstring= new char[100000];
		node* ptr = newst;	
		int i=0,j=0;
		while(ptr != NULL)
		{	
			int m=0;
			while(ptr->p[m] != '\0')
			{
			//	i++;
		//		cout<<"st2 "<<ptr->p[m]<<endl;
				concatstring[count] = ptr->p[m];					
				m++;
				count++;
			}
			ptr = ptr->next;
		}
		concatstring[count] ='\0';
		return concatstring;
	} 
}; 

stringBuilder stringInitialize(char* temp)
{
	stringBuilder sb=stringBuilder(temp);
	return sb;
}

stringBuilder stringAppend(stringBuilder sb1, stringBuilder sb2)
{
	sb1.tail->next = sb2.head;
//	sb1.tail = sb2.newst->head;	
	sb1.tail = sb2.tail;	
//	stringBuilder sb = stringBuilder(appendedst);
	return sb1;
}

int stringlen(char* st)
{
	int count =0;
	int i =0;
	while(st[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}

int findSubString(stringBuilder sb, char* subst)
{
	int countlen = 0;
	char *concatstring= new char[100000];
	node* ptr = sb.head;
	
	while(ptr != NULL)
	{
		int m=0;
		while(ptr->p[m] != '\0')
		{
			//	i++;
		//		cout<<"st2 "<<newst[1][j]<<endl;
			concatstring[countlen] = ptr->p[m];					
			m++;
			countlen++;
		}
		ptr = ptr->next;
	}

		concatstring[countlen] ='\0';
	//	cout<<strlen(concatstring)<<endl;
		
		int index = -1;
		int orglen = stringlen(concatstring);
	//	cout<<"orglen "<<orglen<<endl;
		int sublen = stringlen(subst);
	//	cout<<"sublen "<<sublen<<endl;
		int i =0;
		int j = 0;
		int ismatched = 0;
		int perfectmatched = 0;
		int count = 0;
		while(i < orglen)
		{
			if(concatstring[i] == subst[j])
			{
				count++;
				if(ismatched ==0)
				{
					index = i;
					ismatched = 1;
				}
			//	i++;
				j++;			
			}
			else
			{
				i = i-count;
				count = 0;
				j= 0;
				ismatched = 0;
				index = -1;
			//	i++;
			}
			i++;

			if(count == sublen)
			{
				perfectmatched = 1;
				break;
			}
		}
		
		if(perfectmatched == 1)
			return index;
		else 
			return -1;
	
}

 int main()
 {
 	stringBuilder sb1 = stringInitialize("hello");
 	stringBuilder sb2 = stringInitialize("world");
	cout<<"sb1 "<<sb1.toString()<<endl;
 	cout<<"sb2 "<<sb2.toString()<<endl;
 	stringBuilder sb3 = stringAppend(sb1,sb2);
 	cout<<"sb2 "<<sb2.toString()<<endl;
 	cout<<"sb3 "<<sb3.toString()<<endl;
 	stringBuilder sb5 = stringInitialize("indranil");
 	stringBuilder sb4 = stringAppend(sb1,sb2);
 	cout<<"sb4 "<<sb4.toString()<<endl;
 	int index1 = findSubString(sb1,"hell");
 	cout<<"index1 "<<index1<<endl;
 	int index2 = findSubString(sb3,"or");
	cout<<"index2 "<<index2<<endl;
	return 0;
 }
