#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//Failed and successful trans
int failure=0;
int success=0;
void Trans(int a)
{
    if(a==0)
        failure++;
    else
        success++;
}
class Product
{
//PRIVATE SECTION FOR SELLER (PART 001)
private:
    int SKU;
    string product; //product name
    string brand;  //Brand name
    double price; //Selling Price
    double stock;//available stock unit counter

//PRODUCT DETAILS UPDATE PART
    void priceUpdate()
    {
        cout<<"\n\t\t\t\t\t\tEnter the new price: ";
        cin>>price;
        cout<<endl;
        system("CLS");
    }
    void stockUpdate()
    {
        cout<<"\n\t\t\t\t\t\tEnter the new stock: ";
        cin>>stock;
        cout<<endl;
        system("CLS");
    }

    //  CONSTRUCTOR AKA MAIN CONSTRUCTOR SITE (PART 002)
public:
    Product(int u,string x,string y, long double w, double v) //Class_name Objects (Parameters)
    {
        SKU=u;
        product=x;
        brand=y;
        price=w;
        stock=v;
    }
    Product(string x,string y)                                           //constructor
    {
        product=x;
        brand=y;
    }
    int search(Product x)                                                  //searching the Product in the list
    {
        if(product==x.product&&brand==x.brand)
            return 1;
        else
            return 0;
    }
         void No_Of_Products()                             //checking no. of copies and calculating the total price
    {
        int n;
        cout<<"\n\t\t\t\t\t\tProducts Details: "<<endl;
        Productdetails();
        cout<<"\t\t\t\t\t\tEnter required number of Products: ";
        cin>>n;
        if(n>stock)
        {
            cout<<"\t\t\t\t\t\tRequired amount is not in stock"<<endl;
            Trans(0);
        }
        else
        {
            cout<<"\n\n\t\t\t\t\t\tTotal cost of the items: "<<n*price<<endl;
            stock=stock-n;
            cout<<"\n\t\t\t\t\t\tRemaining stock: "<<stock<<endl;
            Trans(1);
        }
    }
//CHECK AVAILABLE PRODUCTS
   void Productdetails()
    {
        cout<<"\t\t\t\t\t\tProduct SKU: "<<SKU<<endl;
        cout<<"\t\t\t\t\t\tproduct: "<<product<<endl;
        cout<<"\t\t\t\t\t\tBrand: "<<brand<<endl;
        cout<<"\t\t\t\t\t\tPrice: "<<price<<" Taka"<<endl;
        cout<<"\t\t\t\t\t\tThe stocks available: "<<stock<<endl;
        cout<<endl;
    }
    void update()   //update price and stock
    {
        int x;
        cout<<"\t\t\t\t\t\tSelect what to update\n\t\t\t\t\t\t1. Price\n\t\t\t\t\t\t2. Stock\n\t\t\t\t\t\t3. Go Back"<<endl;
        cin>>x;
        cin.ignore();
        cin.clear();
        system("CLS");
        if(x==1)
            priceUpdate();
        else if(x==2)
            stockUpdate();
    else
        return;
                cin.ignore();
                cin.clear();
                system("CLS");
}
};
    //Add Some object (I mean add some Product & Their Details) (PART 003)
    //After finishing that we'll go "int main()" Function

    Product p1(122,"Steel","BSRM",63000,26000);                //Sku number: 122,      Product:Steel,          Brand:BSRM,              Price: 63K(Per Ton),            Stock available: 26ton
    Product p2(222,"Cement","Holcim",450,1450);               //Sku number: 222,      Product:Cement,        Brand:Holcim,           Price: 450Tk(Per bag),         Stock available: 1450 bag
    Product p3(322,"Sand","Moynamoti",2800,2000);            //Sku number: 322,      Product:Sand,           Brand:Moynamoti,       Price: 63K(Per 100 feet),    Stock available: 2k feet
    Product p4(422,"Bricks","Shapla Bricks",8900,25000);    //Sku number: 142,    Product:Bricks,        Brand: Shapla Bricks   Price: 1000 Pics             Stock available: 25k Pcs


void seller()
{
    int a,n;
    while(1){
    cout<<"\n\t\t\t\t\t\tWELCOME TO MUNNITRAD \n\n\t\t\t\t\t\t1. Products List \n\t\t\t\t\t\t2. Update\n\t\t\t\t\t\t3. Transaction\n\t\t\t\t\t\t4. Main Menu"<<endl;
    cin>>a;
    cout<<endl;
    system("CLS");
    switch(a)
    {
        case 1: cout<<"\n\n\t\t\t\t\t\tWELCOME TO MUNNITRAD\n\n\t\t\t\t\t\tProduct Details:\n\t\t\t\t\t\t_________________________ "<<endl;
                p1.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________"<<endl;
                p2.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________"<<endl;
                p3.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________"<<endl;
                p4.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________\n\n"<<endl;
                break;
            cin.ignore();
            cin.clear();
            system("CLS");

        case 2: cout<<"\n\t\t\t\t\t\tProduct Update\n"<<endl;
                cout<<"\t\t\t\t\t\tAvailable Product: \n\t\t\t\t\t\t1. Products: 122, Steel , BSRM\n\t\t\t\t\t\t2. Products: 222, Cement , Holcim\n\t\t\t\t\t\t3. Products: 322, Sand , Moynamoti\n\t\t\t\t\t\t4. Products: 422, Bricks, Shapla Bricks\n\nEnter the Product SKU for update: ";
                cin>>n;
                cin.ignore();
                cin.clear();
                system("CLS");
                if(n==122)
                    p1.update();
                else if(n==222)
                    p2.update();
                else if(n==322)
                    p3.update();
                else if(n==422)
                    p4.update();
                else
                    cout<<"\t\t\t\t\t\t******\n\t\t\t\t\t\tInvalid\n\t\t\t\t\t\t*****"<<endl;
                    break;
                cout<<"\t\t\t\t\t\tAvailable Product: \n\t\t\t\t\t\t1. Products: 122, Steel , BSRM\n\t\t\t\t\t\t2. Products: 222, Cement , Holcim\n\t\t\t\t\t\t3. Products: 322, Sand , Moynamoti\n\t\t\t\t\t\t4. Products: 422, Bricks, Shapla Bricks\n\nEnter the Product SKU for update: ";
                cin>>n;
                cin.ignore();
                cin.clear();
                system("CLS");

        case 3: cout<<"\n\n\t\t\t\t\t\tTotal failed transaction: "<<failure<<endl;
                cout<<"\t\t\t\t\t\tTotal successful transaction: "<<success<<endl;
                cout<<endl;
                break;
            cin.ignore();
            cin.clear();
            system("CLS");

        case 4:
                return;
    }
   }
}
//Employee options
void Employee()
{
    int a,n;
    while(1){
cout<<"\n\t\t\t\t\t\tWELCOME TO MUNNITRAD \n\n\t\t\t\t\t\t1. Products List \n\t\t\t\t\t\t2. Update\n\t\t\t\t\t\t3. Transaction\n\t\t\t\t\t\t4. Main Menu"<<endl;
    cin>>a;
    cout<<endl;
    system("CLS");
    switch(a)
    {
        case 1: cout<<"\n\t\t\t\t\t\tProduct Details:\n\t\t\t\t\t\t_________________________ "<<endl;
                p1.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________"<<endl;
                p2.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________"<<endl;
                p3.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________"<<endl;
                p4.Productdetails();
                cout<<"\n\t\t\t\t\t\t_________________________\n\n"<<endl;
                break;
            cin.ignore();
            cin.clear();
            system("CLS");

        case 2: cout<<"\n\t\t\t\t\t\tProduct Update\n"<<endl;
                cout<<"\t\t\t\t\t\tAvailable Product: \n\t\t\t\t\t\t1. Products: 122, Steel , BSRM\n\t\t\t\t\t\t2. Products: 222, Cement , Holcim\n\t\t\t\t\t\t3. Products: 322, Sand , Moynamoti\n\t\t\t\t\t\t4. Products: 422, Bricks, Shapla Bricks\n\nEnter the Product SKU for update: ";
                cin>>n;
                cin.ignore();
                cin.clear();
                system("CLS");
                if(n==122)
                    p1.update();
                else if(n==222)
                    p2.update();
                else if(n==322)
                    p3.update();
                else if(n==422)
                    p4.update();
                else
                    cout<<"\t\t\t\t\t\t******\n\t\t\t\t\t\tInvalid\n\t\t\t\t\t\t*****"<<endl;
                    break;
                cout<<"\t\t\t\t\t\tAvailable Product: \n\t\t\t\t\t\t1. Products: 122, Steel , BSRM\n\t\t\t\t\t\t2. Products: 222, Cement , Holcim\n\t\t\t\t\t\t3. Products: 322, Sand , Moynamoti\n\t\t\t\t\t\t4. Products: 422, Bricks, Shapla Bricks\n\nEnter the Product SKU for update: ";
                cin>>n;
                cin.ignore();
                cin.clear();
                system("CLS");

        case 3: cout<<"\n\n\t\t\t\t\t\tTotal failed transaction: "<<failure<<endl;
                cout<<"\n\n\t\t\t\t\t\tTotal successful transaction: "<<success<<endl;
                cout<<endl;
                break;
            cin.ignore();
            cin.clear();
            system("CLS");

        case 4:
                return;
    }
   }
}

    //customer options
void customer()
{
    int x;
    while(1)
    {
        cout<<"\n\n\t\t\t\t\t      WELCOME TO MUNNITRAD\n\n\t\t\t\t\t\tEnter a option \n\t\t\t\t\t\t1.Show all Products\n\t\t\t\t\t\t2.Purchase Products\n\t\t\t\t\t\t3. Main Menu"<<endl;
        cin>>x;
            system("CLS");
        if(x==1)
        {
            cout<<"\n\t\t\t\t\t\t______________________\n\t\t\t\t\t\tProduct Details: \n\t\t\t\t\t\t______________________"<<endl;
            p1.Productdetails();
            p2.Productdetails();
            p3.Productdetails();
            p4.Productdetails();
        }

        else if(x==2)
        {
            string a;
            string b;
            cout<<"\t\t\t\t\t\tAvailable Product: \n\t\t\t\t\t\t1. Products: 122, Steel , BSRM\n\t\t\t\t\t\t2. Products: 222, Cement , Holcim\n\t\t\t\t\t\t3. Products: 322, Sand , Moynamoti\n\t\t\t\t\t\t4. Products: 422, Bricks, Shapla Bricks";
            cout<<"\n\t\t\t\t\t\tEnter product name: ";
            cin>>a;
            cout<<"\t\t\t\t\t\tEnter brand name: ";
            cin>>b;
        cin.ignore();
        system("CLS");
            Product p6(a,b);
            if(p6.search(p1)==1)
                p1.No_Of_Products();
            else if(p6.search(p2)==1)
                p2.No_Of_Products();
            else if(p6.search(p3)==1)
                p3.No_Of_Products();
            else if(p6.search(p4)==1)
                p4.No_Of_Products();
            else
            {
            cout<<"\t\t\t\t\t\tThis Products are not available!"<<endl;
            Trans(0);
            }
        }
        else
            return;
    }
        cin.clear();
}
void Dealers()
{
    cout<<"\n\t\t\t\t\t\tWelcome To MunniTrad\n\n\t\t\t\t\t\tOur Valuable Brands dealership\n\t\t\t\t\t\t1. BSRM\n\t\t\t\t\t\t2. Holcim\n\t\t\t\t\t\t3. Moynamoti\n\t\t\t\t\t\t4. Shapla Bricks"<<endl;
}

//FEEDBACK OPEARATION
void feedback()
{
fstream FEEDBACK;
        FEEDBACK.open("\t\t\t\t\t\tPeople's Feedback!",ios::out);
        cout<<"\n\n\t\t\t\t\t\tHave the feedback? We'd love to hear it, But please don't share sensitive information!\n";
        cin.ignore();

        cout<<"\n\n\t\t\t\t\t\t01. Enter Name: ";
        string Name;
        getline(cin, Name);
        cin.clear();
        FEEDBACK<<Name<<endl;

        cout<<"\t\t\t\t\t\t02. Enter Feedback: ";
        string feedback;
        getline(cin, feedback);
        cin.clear();
        FEEDBACK<<feedback<<endl;

        cout<<"\t\t\t\t\t\t-------------------------------------Thank you so much for your valuable Feedback!-------------------------------------"<<endl;
        FEEDBACK.close();
        cin.ignore();
        system("CLS");
}

int main()
{
    //Here We'll made option based program for Seller, Feedback & Customer (PART 004)
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Color Change
    int a;
    while(1)
    {
        cout<<"\n\t\t\t\t\t\tWELCOME TO MUNNITRAD"<<endl;
        cout<<"\n\t\t\t\t\t\tEnter your identity:\n\n\t\t\t\t\t\t1. Seller\n\t\t\t\t\t\t2. Employee\n\t\t\t\t\t\t3. Customer\n\t\t\t\t\t\t4. Brand Dealership\n\t\t\t\t\t\t5. Feedback\n\t\t\t\t\t\t0. Exit"<<endl;
        cin>>a;
        cout<<endl;
            system("CLS");

        if(a==1){
            seller();
            system("CLS");
        }
        else if(a==2){
            Employee();
            system("CLS");
        }
        else if(a==3){
                customer();
            system("CLS");
        }
        else if(a==4){
                Dealers();
        }
        else if(a==5){
            feedback();
        }
        else
        return 0;
    }
}
