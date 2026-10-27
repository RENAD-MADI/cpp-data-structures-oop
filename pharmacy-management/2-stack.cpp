#include <iostream>
#include <list>
#include <string>
using namespace std;

class Branch
{
private:
    int ID;
    string Address;
    string DrugList;
    string PharmacistList;
    int Phone;
    
public:
	//-----------------setters-----------------//

    void setID(int id)
    {
        ID = id;
    }

    void setAddress(string address)
    {
        Address = address;
    }

    void setPhone(int phone)
    {
        Phone = phone;
    }

    //-----------------getters-----------------//

    int getID()
    {
        return ID;
    }
    
    string getAddress()
    {
        return Address;
    }

    int getPhone()
    {
        return Phone;
    }
};

class Pharmacist 
{
private:
    int ID;
    string Name;
    string LicenseID;
    double Salary;
    int Sales;

public:
	//-----------------setters-----------------//

    void setID(int id)
    {
        ID = id;
    }

    void setName(string name)
    {
        Name = name;
    }

    void setLicenseID(string licenseID)
    {
        LicenseID = licenseID;
    }

    void setSalary(int salary)
    {
        Salary = salary;
    }

    void setSales(int sales)
    {
        Sales = sales;
    }

    //-----------------getters-----------------//

    int getID()
    {
        return ID;
    }

    string getName()
    {
        return Name;
    }

    string getLicenseID()
    {
        return LicenseID;
    }

    double getSalary()
    {
        return Salary;
    }

    int getSales()
    {
        return Sales;
    }
};

class Drug
{
private:
    int ID;
    string Title;
    double Price;
    int Quantity;

public:
	//-----------------setters-----------------//

    void setID(int id)
    {
        ID = id;
    }

    void setTitle(string title)
    {
        Title = title;
    }

    void setPrice(int price)
    {
        Price = price;
    }

    void setQuantity(int quantity)
    {
        Quantity = quantity;
    }

    //-----------------getters-----------------//

    int getID()
    {
        return ID;
    }

    string getTitle()
    {
        return Title;
    }

    double getPrice()
    {
        return Price;
    }

    int getQuantity()
    {
        return Quantity;
    }
};

class Customer
{
private:
    int ID;
    string Name;
    int Phone;
    string Email;

public:
	//-----------------setters-----------------//

    void setID(int id)
    {
        ID = id;
    }

    void setName(string name)
    {
        Name = name;
    }

    void setPhone(int phone)
    {
        Phone = phone;
    }

    void setEmail(string email)
    {
        Email = email;
    }

    //-----------------getters-----------------//

    int getID()
    {
        return ID;
    }

    string getName()
    {
        return Name;
    }

    int getPhone()
    {
        return Phone;
    }

    string getEmail()
    {
        return Email;
    }
};

class DrugNode
{
public:
    Drug drug;
    DrugNode *next;
    
    void display()
    {
        cout<<"the drug ID:"<<drug.getID()<<endl;
        cout<<"the drug title:"<<drug.getTitle()<<endl;
        cout<<"the drug price:"<<drug.getPrice()<<endl;
        cout<<"the drug quantity:"<<drug.getQuantity()<<endl;
        cout<<endl;
    }
};

class DrugList
{
private:
    DrugNode *top;
public:
    DrugList(){top = NULL;}
    void push()
    {
        Drug dg;
        int id;
        string ti;
        double pr;
        int qu;

        cout<<"enter drug ID:   ";
        cin>>id;
        cout<<"enter drug title:   ";
        cin>>ti;
        cout<<"enter drug price:   ";
        cin>>pr;
        cout<<"enter drug quantity:   ";
        cin>>qu;

        dg.setID(id);
        dg.setTitle(ti);
        dg.setPrice(pr);
        dg.setQuantity(qu);
        
        DrugNode *newnode = new DrugNode();
        newnode->drug = dg;
        if(top == NULL)
        {
            newnode->next = NULL;
            top=newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }
        else
        {
            newnode->next = top;
            top = newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }

    }

    void display()
    {
        DrugNode *temp=top;
        if(top == NULL)
            cout<<"list is empty..\n";
        
        while(temp!=NULL)
        {
            temp->display();
            temp=temp->next;
        }
    }

    void pop()
    {
        if(top == NULL)
            cout<<"list is empty..\n";
        else
        {
            DrugNode *delptr = top;
            top = top->next;
            delete delptr;
            cout<<"\tSuccessfully poped...!\n\n";
        }
    }

    void find()
    {
        int key;
        DrugNode *temp = top;

        cout<<"Enter Customers ID You want to find:  ";
        cin>>key;
        
        if(temp == NULL)
            cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->drug.getID() == key)
            {
                temp->display();
                break;
            }
            else if(temp->next != NULL)
            temp = temp->next;
            else
            {
                cout<<"id not found!\n";
                break;
            }
        }
    }

    void modify()
    {
        int key;
        int id;
        string ti;
        double pr;
        int qu;

        Drug UpdateDrug;

        DrugNode *temp =top;

        cout<<"Enter drug ID You want to modify:  ";
		cin>>key;
            if(temp == NULL)
    		   cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->drug.getID() == key)
            {
                cout<<"\nEnter the new data to update the old data of drug"<<endl;
                cout<<"enter drug ID:   ";
                cin>>id;
                cout<<"enter drug title:   ";
                cin>>ti;
                cout<<"enter drug price:   ";
                cin>>pr;
                cout<<"enter drug quantity:   ";
                cin>>qu;

                UpdateDrug.setID(id);
                UpdateDrug.setTitle(ti);
                UpdateDrug.setPrice(pr);
                UpdateDrug.setQuantity(qu);

                temp->drug = UpdateDrug;
                cout<<"\nSuccessfully Modified...!\n\n";
                break;
            }
            else if(temp->next != NULL)
                temp = temp->next;
            else
            {
                cout<<"id not found...";
                break;
            }
        }
    }
};

class PharmacistNode
{
public:
    Pharmacist pharmacist;
    PharmacistNode *next;

    void display()
    {
        cout<<"the pharmacist ID:"<<pharmacist.getID()<<endl;
        cout<<"the pharmacist Name:"<<pharmacist.getName()<<endl;
        cout<<"the pharmacist LicenseID:"<<pharmacist.getLicenseID()<<endl;
        cout<<"the pharmacist salary:"<<pharmacist.getSalary()<<endl;
        cout<<"the pharmacist sales:"<<pharmacist.getSales()<<endl;
        cout<<endl;
    }
};

class Pharmacistlist
{
private:
    PharmacistNode *top;
public:
    Pharmacistlist(){top = NULL;}
    void push()
    {
        Pharmacist ph;
        int i;
        string n;
        string l;
        double sly;
        int sls;

        cout<<"enter pharmacist ID:   ";
        cin>>i;
        cout<<"enter pharmacist Name:   ";
        cin>>n;
        cout<<"enter pharmacist LicenseID:   ";
        cin>>l;
        cout<<"enter pharmacist salary:   ";
        cin>>sly;
        cout<<"enter pharmacist sales:   ";
        cin>>sls;

        ph.setID(i);
        ph.setName(n);
        ph.setLicenseID(l);
        ph.setSalary(sly);
        ph.setSales(sls);

        PharmacistNode *newnode = new PharmacistNode();
        newnode->pharmacist = ph;
        if(top == NULL)
        {
            newnode->next = NULL;
            top=newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }
        else
        {
            newnode->next = top;
            top = newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }
    }

    void display()
    {
        PharmacistNode *temp = top;
        if(top == NULL)
            cout<<"list is empty..\n";
        
        while(temp!=NULL)
        {
            temp->display();
            temp=temp->next;
        }
    }

    void pop()
    {
        if(top == NULL)
            cout<<"list is empty..\n";
        else
        {
            PharmacistNode *delptr = top;
            top = top->next;
            delete delptr;
            cout<<"\tSuccessfully poped...!\n\n";
        }
    }
    
    void find()
    {
        int key;
        PharmacistNode *temp = top;

        cout<<"Enter pharmacist ID You want to find:  ";
        cin>>key;
        
        if(temp == NULL)
            cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->pharmacist.getID() == key)
            {
                temp->display();
                break;
            }
            else if(temp->next != NULL)
            temp = temp->next;
            else
            {
                cout<<"id not found!\n";
                break;
            }
        }
    }

    void modify()
    {
        int key;
        int i;
        string n;
        string l;
        double sly;
        int sls;

        Pharmacist Updatepharmacist;

        PharmacistNode *temp =top;

        cout<<"Enter pharmacist ID You want to modify:  ";
		cin>>key;
            if(temp == NULL)
    		   cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->pharmacist.getID() == key)
            {
                cout<<"\nEnter the new data to update the old data of pharmacist"<<endl;
                cout<<"enter pharmacist ID:   ";
                cin>>i;
                cout<<"enter pharmacist Name:   ";
                cin>>n;
                cout<<"enter pharmacist LicenseID:   ";
                cin>>l;
                cout<<"enter pharmacist salary:   ";
                cin>>sly;
                cout<<"enter pharmacist sales:   ";
                cin>>sls;   

                Updatepharmacist.setID(i);
                Updatepharmacist.setName(n);
                Updatepharmacist.setLicenseID(l);
                Updatepharmacist.setSalary(sly);
                Updatepharmacist.setSales(sls);

                temp->pharmacist = Updatepharmacist;
                cout<<"\nSuccessfully Modified...!\n\n";
                break;
            }
            else if(temp->next != NULL)
                temp = temp->next;
            else
            {
                cout<<"id not found...";
                break;
            }
        }
    }
};

class CustomerNode
{
public:
    Customer customer;
    CustomerNode *next;

    void display()
    {
        cout<<"the customer ID:"<<customer.getID()<<endl;
        cout<<"the customer name:"<<customer.getName()<<endl;
        cout<<"the customer phone:"<<customer.getPhone()<<endl;
        cout<<"the customer email:"<<customer.getEmail()<<endl;
        cout<<endl;
    }
};

class Customerlist
{
private:
    CustomerNode *top;
public:
    Customerlist(){top = NULL;}
    void push()
    {
        Customer cu;
        int i;
        string n;
        int p;
        string e;

        cout<<"enter customer ID:   ";
        cin>>i;
        cout<<"enter customer name:   ";
        cin>>n;
        cout<<"enter customer phone:   ";
        cin>>p;
        cout<<"enter customer email:   ";
        cin>>e;

        cu.setID(i);
        cu.setName(n);
        cu.setPhone(p);
        cu.setEmail(e);
        
        CustomerNode *newnode = new CustomerNode();
        newnode->customer = cu;
        if(top == NULL)
        {
            newnode->next = NULL;
            top=newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }
        else
        {
            newnode->next = top;
            top = newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }
    }

    void display()
    {
        CustomerNode *temp=top;
        if(top == NULL)
            cout<<"list is empty..\n";
        
        while(temp!=NULL)
        {
            temp->display();
            temp=temp->next;
        }
    }

    void pop()
    {
        if(top == NULL)
            cout<<"list is empty..\n";
        else
        {
            CustomerNode *delptr = top;
            top = top->next;
            delete delptr;
            cout<<"\tSuccessfully poped...!\n\n";
        }
    }

    void find()
    {
        int key;
        CustomerNode *temp = top;

        cout<<"Enter Customers ID You want to find:  ";
        cin>>key;
        
        if(temp == NULL)
            cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->customer.getID() == key)
            {
                temp->display();
                break;
            }
            else if(temp->next != NULL)
            temp = temp->next;
            else
            {
                cout<<"id not found!\n";
                break;
            }
        }
    }

    void modify()
    {
        int key;
        int i;
        string n;
        int p;
        string e;

        Customer Updatecustomer;

        CustomerNode *temp =top;

        cout<<"Enter customer ID You want to modify:  ";
		cin>>key;
            if(temp == NULL)
    		   cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->customer.getID() == key)
            {
                cout<<"\nEnter the new data to update the old data of customer"<<endl;
                cout<<"enter customer ID:   ";
                cin>>i;
                cout<<"enter customer name:   ";
                cin>>n;
                cout<<"enter customer phone:   ";
                cin>>p;
                cout<<"enter customer email:   ";
                cin>>e;

                Updatecustomer.setID(i);
                Updatecustomer.setName(n);
                Updatecustomer.setPhone(p);
                Updatecustomer.setEmail(e);

                temp->customer = Updatecustomer;
                cout<<"\nSuccessfully Modified...!\n\n";
                break;
            }
            else if(temp->next != NULL)
                temp = temp->next;
            else
            {
                cout<<"id not found...";
                break;
            }
        }
    }
};

class BranchNode
{
public:
    
    DrugList drug;
    Pharmacistlist pharmacist;
    Branch branch;
    BranchNode *next;
    void display(void)
    {
        cout<<"the branch ID:"<<branch.getID()<<endl;
        cout<<"the branch address:"<<branch.getAddress()<<endl;
        cout<<"the branch phone:"<<branch.getPhone()<<endl;
    }
};

class Branchlist
{
private:
    BranchNode *top;
public:
    Branchlist(){top = NULL;}
    void push()
    {
        Branch B;
        int B_id,B_phone;
        string B_adress;

    

        cout << "Enter Branch ID: ";
		cin >> B_id;
		cout << "Enter branch phone: ";
		cin >> B_phone;
        cout << "Enter branch adress: ";
		cin >> B_adress;
    

        B.setID(B_id);
        B.setPhone(B_phone);
        B.setAddress(B_adress);

        BranchNode *newnode = new BranchNode();
        newnode->branch = B;
        if(top == NULL)
        {
            newnode->next = NULL;
            top=newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }
        else
        {
            newnode->next = top;
            top = newnode;
            cout<<"\nSuccessfully pushed..!\n\n";
        }    
    }

    void display()
    {
        BranchNode *temp=top;
        if(top == NULL)
            cout<<"list is empty..\n";
        
        while(temp!=NULL)
        {
            temp->display();
            temp=temp->next;
        }
    }

    void pop()
    {
        if(top == NULL)
            cout<<"list is empty..\n";
        else
        {
            BranchNode *delptr = top;
            top = top->next;
            delete delptr;
            cout<<"\tSuccessfully Removed...!\n\n";
        }
    } 

    void find()
    {
        int key;
        BranchNode *temp = top;

        cout<<"Enter Customers ID You want to find:  ";
        cin>>key;
        
        if(temp == NULL)
            cout<<"List is empty...";
        while(temp != NULL)
        {
            if(temp->branch.getID() == key)
            {
                temp->display();
                break;
            }
            else if(temp->next != NULL)
            temp = temp->next;
            else
            {
                cout<<"id not found!\n";
                break;
            }
        }
    }

    void modify()
    {
        int key;

        Branch UpdateBranch;
        int B_id,B_phone;
        string B_adress;
        
        BranchNode *temp = top;
        cout << "Enter Branch's ID You want to Modify:  ";
		cin >> key;
        if (temp == NULL)
			cout << "List is empty...";
		while (temp != NULL)
        {
			if(temp->branch.getID() == key)
            {
                cout << "\nEnter the new data to update the old data of Customer" << endl;
            cout << "Enter Branch ID: ";
		    cin >> B_id;
		    cout << "Enter branch phone: ";
		    cin >> B_phone;
            cout << "Enter branch adress: ";
		    cin >> B_adress;

            UpdateBranch.setID(B_id);
            UpdateBranch.setPhone(B_phone);
            UpdateBranch.setAddress(B_adress);

            temp->branch = UpdateBranch;
            cout << "\nSuccessfully Modified...!\n\n";
			break;
            }
            else if (temp->next != NULL) {
				temp = temp->next;
			}
			else
			{
				cout << "\nOops! ID not found...";
				break;
			}
        }
    }
};

char subMenu(){
	char a;
                            cout<<"\t\t\t Sub_MENU \n\n";
    cout<<"(d) Display"<<endl<<endl;
    cout<<"(i) push"<<endl<<endl;
    cout<<"(r) pop"<<endl<<endl;
    cout<<"(m) Modify"<<endl<<endl;
    cout<<"(f) Find"<<endl<<endl;

    cout<<"Select your option (above): ";cin>>a;
	return a;
}

int main()
{
    int mainChoice;
    char ch;
    DrugList dg;
    Pharmacistlist ph;
    Customerlist cu;
    Branchlist br;
    do{
    cout << "Main menu:" <<endl;
    cout << "1. Branch" <<endl;
    cout << "2. Drug" <<endl;
    cout << "3. Pharmacist" <<endl;
    cout << "4. Customer" <<endl;
    cout << "0. Exit" <<endl;
    cout << "Enter your choice: ";
    cin >> mainChoice;
    
    switch (mainChoice) {
        case 1:
            ch = subMenu();
                if(ch == 'd')
         		    br.display();
			    else if(ch == 'i')
         		    br.push();
			    else if(ch == 'r')
         		    br.pop();
			    else if(ch == 'm')
         		    br.modify();
			    else if(ch == 'f')
         		    br.find();
                break;
            break;
        case 2:
            ch = subMenu();
                if(ch == 'd')
         		    dg.display();
			    else if(ch == 'i')
         		    dg.push();
			    else if(ch == 'r')
         		    dg.pop();
			    else if(ch == 'm')
         		    dg.modify();
			    else if(ch == 'f')
         		    dg.find();
                break;
        case 3:
            ch = subMenu();
                if(ch == 'd')
         		    ph.display();
			    else if(ch == 'i')
         		    ph.push();
			    else if(ch == 'r')
         		    ph.pop();
			    else if(ch == 'm')
         		    ph.modify();
			    else if(ch == 'f')
         		    ph.find();
                break;
        case 4:
            ch = subMenu();
                if(ch == 'd')
         		    cu.display();
			    else if(ch == 'i')
         		    cu.push();
			    else if(ch == 'r')
         		    cu.pop();
			    else if(ch == 'm')
         		    cu.modify();
			    else if(ch == 'f')
         		    cu.find();  
                break;
        case 0:
                cout << "Exiting the program." <<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(mainChoice != 0);
}