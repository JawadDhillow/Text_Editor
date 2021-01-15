#include<iostream>
#include<string>
using namespace std;

class Node
{
	public:
		int key;
		string data;
		
		Node* next;
		
		Node()
		{
			key=0;
			data;
			next=NULL;
		}
		Node(int k,string d)
		{
			key=k;
			data=d;
		}
};

class SinglyLinkedList
{
	public:
		Node* head;
		
		SinglyLinkedList()
		{
			head=NULL;
		}
		SinglyLinkedList(Node *n)
		{
			head=n;
		}
		//Check IF node exist using key value
		Node* NodeExist(int k)
		{
			Node* temp=NULL;
			
			Node* ptr=head;
			while(ptr!=NULL)
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
		}
		
		void appendNode(Node *n)
		{
			if(NodeExist(n->key)!=NULL)
			{
				cout<<"Node already exist by key"<<n->key<<"append another key ";
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					cout<<"Node appended"<<endl;
				}
				else
				{
					Node* ptr=head;
					while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				
				cout<<"node Appended"<<endl;
				}
			}
		}
		
		//Prepend node -attach a node at start
		
		void prependNode(Node* n)
		{
				if(NodeExist(n->key)!=NULL)
			{
				cout<<"Node already exist by key"<<n->key<<"append another key ";
			}
			else
			{
				n->next=head;
				head=n;
				cout<<"Node prepended:";
			}
		}
		
		//Insert a node after a particular node in list
		void insertNodeAfter(int k,Node *n)
		{
		
			Node* ptr =NodeExist(k);
			if(ptr==NULL)
			{
				cout<<"NO nODE ALREADY EXIST by key:"<<k<<endl;
			}
			else
			{
				if(NodeExist(n->key)!=NULL)
				{
					cout<<"Node already exist by key"<<n->key<<"append another key ";
				}
				else
				{
					n->next=ptr->next;
					ptr->next=n;
					cout<<"node Inserted:"<<endl;
				}
			}
		}
		
		//Delete a node by key;
		
		void DeletNode(int k)
		{
			if(head==NULL)
			{
				cout<<"No node to delete as empety list:"<<endl;
			}
			else if(head!=NULL)
			{
				if(head->key==k)
				{
					head=head->next;
					cout<<"Node unlinked eith key value"<<k<<endl;
				}
				else
				{
					Node* temp=NULL;
					Node* prevptr=head;
					Node* currentptr=head->next;
					while(currentptr!=NULL)
					{
						if(currentptr->key==k)
						{
							temp=currentptr;
							currentptr=NULL;
						}
						else
						{
							prevptr=prevptr->next;
							currentptr=currentptr->next;
						}
					}
						if(temp!=NULL)
						{
							prevptr->next=temp->next;
							cout<<"Node Unlinked with key value: "<<k<<endl;
						}
						else
						{
						cout<<"Node dosenot exist witk key value:"<<k<<endl;	
						}
				}
			}
		}
		
		void UpdateNode(int k,string d)
		{
			Node* ptr=NodeExist(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"Node data update with key vaue :"<<k<<endl;
			}
			else
			{
				cout<<"Node Dosenot exit with key value:"<<k<<endl;
			}
		}
		
		void Printlist()
		{
			if(head==NULL)
			{
				cout<<"No node in the linked list:"<<endl;
			}
			else
			{
				cout<<"Text values:"<<endl;
				Node* temp=head;
				while(temp!=NULL)
				{
					cout<<temp->data<<", ";
					temp=temp->next;
				}
			}
				
		}
		
};

int main()
{
	SinglyLinkedList s;
	int option;
	int key1,k1;
	string data1;
	do
	{
		cout<<"\n\t\t\t\tWelcome To the TextEditor Basic Version 0.1 \n\n\t\t\t\t\tSelect from options:"<<endl;
		cout<<"\n\n\n";
		cout<<"1. Write"<<endl;
		cout<<"2. Write at the Start"<<endl;
		cout<<"3. Write at Specific Position"<<endl;
		cout<<"4. Delete a Line"<<endl;
		cout<<"5. Update the line"<<endl;
		cout<<"6. Print The Text"<<endl;
		cout<<"7. Clear Screen"<<endl;
		
		cin>>option;
		Node* n1=new Node();
	//	Node n1;
		
		switch(option)
		{
			case 0:
			break;
			case 1:
			cout<<"Append the node//Enter the key and data to be added"<<endl;
			cout<<"eNTER THE KEY:"<<endl;
			cin>>key1;
			cout<<"Enter the data:"<<endl;
			cin>>data1;
			n1->key=key1;
			n1->data=data1;
			s.appendNode(n1);
			break;
			
			case 2:
			cout<<"prepend the node//Enter the key and data to be added"<<endl;
			cout<<"eNTER THE KEY:"<<endl;
			cin>>key1;
			cout<<"Enter the data:"<<endl;
			cin>>data1;
			n1->key=key1;
			n1->data=data1;
			s.prependNode(n1);
			
			break;
			
			case 3:
			cout<<"insert the node//Enter the key and data to be added"<<endl;
			cout<<"eNTER THE KEY:"<<endl;
			cin>>key1;
			cout<<"Enter the data:"<<endl;
			cin>>data1;
			n1->key=key1;
			n1->data=data1;
			s.insertNodeAfter(k1,n1);
			break;
			
			case 4:
			cout<<"Update node by key operation// endter key of node to be deleted:"<<endl;
			cin>>k1;
			s.DeletNode(k1);
			break;
			
			case 5:
			cout<<"Update node by key operation//enter key and data to update;"<<endl;
			cin>>key1;
			cin>>data1;
			s.UpdateNode(key1,data1);
			break;
			
			case 6:
			s.Printlist();
			break;
			
			case 7:
				system("cls");
				break;
			
			default:
			cout<<"Enter the numer option:"<<endl;
			
		}
	}while(option!=0);
	
	
};





























