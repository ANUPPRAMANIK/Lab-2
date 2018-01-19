#include<iostream>
using namespace std;
class node // to create a class of type node
{  
	public :
    int data;
    node *next;
};
class link // to create a class of type link
{
    node *head;  // to create head node
    node *tail;  // to create tail node
  public:
    link () // this is a constructor
    {
      head = NULL;  // to make head null
      tail = NULL;  // to make head null
    }
       void insert_list(int data);
       void insert_at(int pos, int data);
       void delete_list();
       void delete_at(int pos);
       void display_l();
       int count_l();
};
void menu()  // this is the menu of functions one can use
{ 
	cout<< " \n this is the list of thing you can do using this programme " <<endl;
	cout<< " (a) to create a linked list " <<endl;
	cout<< " (b) to insert data in linked list " <<endl;
	cout<< " (c) to insert a data at any position " <<endl;
	cout<< " (d) to delete the linked list " <<endl;
	cout<< " (e) to delete data of a specific position " <<endl;
	cout<< " (f) to display the elements of linked list " <<endl;
	cout<< " (g) to count the number of elements in the list " <<endl;
	cout<< " press 'x' and then press 'enter' to exit " <<endl;
	cout<< " choose the option you want to do : \n -> " ;
}
int main()
{
	char chr;  // this is a character type variable
	link l_l; // to create an object
	// now start while loop
	while (chr != 'x')  // condition is that the input is not x, otherwise break the loop
   { 
   	menu();
     cin>> chr;
     // to give different outputs depending on the character variable using 'if else'
     if (chr =='a') 
     {
        cout<< " \n linked list is created " ;
     }
     else 
     if (chr =='b')
     {
         int num;
         cout<< " \n how many data you want to add? \n -> " ;
         cin>>num;
         for(int i=1; i<=num; i++)
         {   
         	int data;
             cout<< " data " <<i<< " = " ;
             cin>> data;
             l_l.insert_list(data); // for calling the insert_list(int data) function
         }
     }
     else 
     if (chr =='c')
     {   
     	int post, data;
     	int num;
         num = l_l.count_l(); // for calling the count_l() function to check the number element in the list
         cout<< " \n enter the position where you want to insert data: " ;
         cin>>post;
         if (0 < post && post < num+1) // this is a condition for non-empty linked list
         {
             cout<< " \n enter the new data: " ;
             cin>> data;
             l_l.insert_at(post, data); // for calling the insert_at() function
         }
         else 
         {
         	cout<< " invalid position \n " ;
         } 
         // the condition when position entered is not valid for the linked list
     }
     else 
     if (chr =='d')
     {
         l_l.delete_list();  // for calling delete_list() function
     }
     else
     if (chr =='e')
     {
         int post;
         int num;
         num = l_l.count_l();  // for calling the count_l() function to check the number element in the list
         cout<< " \n enter the position of data you want to delete: " ;
         cin>> post;
         if (0 < post && post <= num)  // the condition for nonempty linked list
         {
             l_l.delete_at(post);  // for calling the delete_at() function
         }
         else 
         {
         	cout<< " invalid position " ;
         	}  // the condition when position entered is not valid for the linked list
     }
     else
     if (chr =='f')
     {
         cout<< " these are your data: "<<endl;
         l_l.display_l();  // for calling the display_l() function
     }
     else 
     if (chr =='g')
     {   
     	int num;
         num = l_l.count_l();  // for calling the count_l() funtion
         cout<< " \n there are the ";
         cout<<num;
         cout<< " elements in your linked list \n ";
     }
     else
        {
             cout<<" \n you have entered an invalid key. \n try again " ;  // if one enters an invalid character
        }
     cout<< " \n thank you for using this programme ";
     cout<< " \n if you want to continue press any key and then press 'enter' " ;  // to run the while loop again
     cout<< " \n if you want to exit press 'x' and then press 'enter' \n -> " ;   // to break the while loop
     cin>> chr; 
   }
return 0;
}
void link :: insert_list(int data)
{
     node *temp = new node; // to create a new node type object called 'temp'
     temp->data = data;   // the data input is inserted in data part of temp
     if (head == NULL)   // this is a condition for empty list
     {
         head=temp;   // to make 'head' and 'temp' same
         tail=temp;   // to make 'tail' and 'temp' same
         temp->next = NULL;  // this points 'next' of temp to null
     }
     else   // this is a condition for nonempty list
        {
           tail->next = temp;  // this points 'next' of tail to temp
           temp->next = NULL;  // this points 'next' pointer of temp to null
           tail=temp;   // to make 'temp' and 'tail' same
        }
}
void link :: insert_at(int post, int dat)
{
    node *tmp =new node;  // to create a new node type object called 'temp'
    node *pos;   // to create a new node type pointer called 'pos'
    pos=head;   // this makes the address of 'pos' and 'head' same
    tmp->data= dat;
    for (int i=2;i<post;i++)
    {
        pos=pos->next;
    }
    tmp->next = pos->next;
    pos->next = tmp;
}
void link :: delete_list()
{
    node *pos;  // to create a new node type pointer called 'pos'
    pos=head;  // this makes the address of 'pos' and 'head' same
    if (head == NULL)
    {
         cout<< " there is nothing in the list to delete \n " ;
    }
    else
    { 
        while (pos->next != tail)  // to run this loop until 'next' of pos does not point to tail
        {
            pos=pos->next;  // to make the next node new 'pos'
        }
        tail=pos;    // to make 'tail' and 'pos' same
        pos=pos->next;   // to make the next node new 'pos'
        tail->next = NULL;
        delete pos;   // to delete node 'pos'
    }
}
void link :: delete_at(int post)
{ 
	node *pos;  // to create a new node type pointer called 'pos'
  pos=head;   // this makes the address of 'pos' and 'head' same
  for (int i=2;i<post;i++)
  {
      pos=pos->next;
  }
  node *temp;  // to create a new node type pointer called 'temp'
  temp = pos->next;
  pos->next = temp->next;
  temp->next = NULL;
  delete temp;  // to delete node 'temp'
}
void link :: display_l()
{
    node *pos;  // to create a new node type pointer called 'pos'
    pos=head;  // this makes the address of 'pos' and 'head' same
    if (head==NULL)
    {
        cout<< " your list is empty " ;
    }
    else
    {
       while (pos != NULL)
      {
         cout<<pos->data<<" -> ";  // to display the elements
         pos=pos->next; // to go to the next element 
      }
    }
}
int link :: count_l()
{
    node *pos;  // to create a new node type pointer called 'pos'
    pos = head;  // this makes the address of 'pos' and 'head' same
    int i=2;
    if (head == NULL)   // when the number of elements in the list is zero
    {
        return 0;
    }
    else if (pos->next == NULL) // when the number of elements in the list is one
    {
        return 1;
    }
    else
    {
        while (pos->next != tail)
        {
            pos = pos->next;
            i++;
        }
        return i; // to return the number of elements present
    }
}
