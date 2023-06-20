#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
/*Mini Project -ATM
  :-> Check Balance
  :-> Cash withdraw
  :-> User Details
  :-> Update Mobile No.
  */
  class ATM                        //class ATM
  {
      private:                      //private member variable
          long int Account_No;
          string Name;
          double Balance ;
          int PIN;
          int  Mobile_No;
      public:                       //public member function
          // setData function is setting the Data into the private member varible
          void setData(long int account_no, string name, int pin, double balance , int  mobile_no)
          {
            Account_No=  account_no;
            Name=name;
            Balance =balance;
            PIN=pin;
            Mobile_No=mobile_no;
          }
          long int getAccountNo()
          {
              return Account_No;
          }
          string getName()
          {
              return Name;
          }
          double getBalance()
          {
              return Balance;
          }
          int getPIN()
          {
              return PIN;
          }
          int getMobileNo()
          {
              return Mobile_No;
          }
          //setMobile function is Updating the user mobile no
          void setMobile(int mob_prev, int mob_new)
          {
              if(mob_prev == Mobile_No)        // it will check old Mobile no
              {
                  Mobile_No= mob_new;          // and update with new , if old matches
                  cout<<endl<<"Sucessfully updated Mobile no.";
                  _getch();                    //getch is to hold the screen ( untile user press any key)
              }

              else                             // Does not update if mobile no . does not matches
              {
                  cout<<endl<<"Incorrect !! old Mobile no .";
                  _getch();
              }
          }
          // cashwithdraw function is used to withdraw money from atm
          void cashWithDraw(int amount_a)
          {

              if(amount_a >0 && amount_a < Balance)          //check enterd amount validity
              {
                  Balance -=amount_a;                        //balance = balance - amount_a
                  cout<<"Please Collect your Cash "<<endl;
                  cout<<"Available balance :"<<Balance<<endl;
                  -getch();               //getch is to hold the screen ( untile user press any key )
              }

              else
                {
                cout<<endl<<"Invalid Input or Insufficient Balance ";
              _getch();

                }
          }




  };
main()
{
    int choice = 0, enterPIN;        //enterPIN and EnterAccountNo. --> user authentication
    long int EnterAccountNo;

    system("cls");

    // created user ( object )
    ATM costumer1;
    // set user details ( into object )   ( setting default data)
    costumer1.setData(1234567,"Ujjwal Nimbokar",1020,45000.90,9156180238);

    do
    {
        system("cls");

        cout<<endl<<"****Welcome to ATM****"<<endl;
        cout<<"Enter your account no ";                  // asking user to enter account no
        cin>>EnterAccountNo;
        cout<<"Enter PiN"<<endl;                          // asking user to enter PIN
        cin>>enterPIN;

        // check whether enter values matches with user details
        if((EnterAccountNo == costumer1.getAccountNo()) && (enterPIN == costumer1.getPIN()))
        {
            do
            {
                int amount =0;
                int oldMobileNo, newMobileNo;

                system("cls");
                // user Interface

                cout<<endl<<"**** Welcome to ATM ****"<<endl;
                cout<<"Select option "<<endl;
                cout<<"1. Check Balance"<<endl;
                cout<<"2. Cash withdraw"<<endl;
                cout<<"3. Show User details "<<endl;
                cout<<"4.update mobile no.";
                cout<<"5. Exit"<<endl;
                cin>>choice;                        // taking user choice
                switch(choice)                      // switch condition
                {
                    case 1:
                    cout<<endl<<"Your bank Balance is :"<<costumer1.getBalance()<<endl;
                                                     // getbalance .... printing the user bank balance
                    _getch();
                    break;

                    case 2:
                        cout<<endl<<"Enter the amount :";
                        cin>>amount;
                        costumer1.cashWithDraw(amount);
                        break;

                    case 3:
                        cout<<"**** User Details are :-"<<endl;
                        cout<<"->   Account No  "<<costumer1.getAccountNo()<<endl;
                        cout<<"->   Name        "<<costumer1.getName()<<endl;
                        cout<<"->   Balance     "<<costumer1.getBalance()<<endl;
                        cout<<"->   Mobile No   "<<costumer1.getMobileNo()<<endl;

                        _getch();
                        break;

                    case 4:
                        cout<<"Enter old mobile no ."<<endl;
                        cin>>oldMobileNo;
                        cout<<"Enter New Mobile No ."<<endl;
                        cin>>newMobileNo;

                        costumer1.setMobile(oldMobileNo, newMobileNo);
                        break;
                    case 5:
                        exit(0);
                    default :
                        cout<<"Enter valid Data !!!"<<endl;


                }

           }while(1);

    }

}   while(1);
}
