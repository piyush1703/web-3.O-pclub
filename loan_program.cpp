#include<iostream>
using namespace std;
#include <cmath>
#include <algorithm>
class loan
{
private:
   
public:
double installement(double principle,int time);
    double balance(double principle,double roi,int i,int time);
     void display(double principle,double roi,int time);
};
// display function to show year wise chart for the loan amount for the years you have taken
void loan::display(double principle,double roi,int time)
{
    cout<<"No.     Balance     installement       interest     Total Payment "<<endl;
    cout<<"........................................................................"<<endl;
    for(int i=1;i<=time;i++){
        cout<<i<<"         "<<balance(principle,roi,i,time)<<"           "<<installement(principle,time)<<"       "<<((balance(principle,roi,i,time)*roi*1)/(time*100))<<"       "<<installement(principle,time)+(balance(principle,roi,i,time)*roi*1)/(time*100)<<endl;
    }
     cout<<"........................................................................"<<endl;
     double sumint=0.00,suminst=0.00;
     for(int i=1;i<=time;i++){
         sumint=sumint+(balance(principle,roi,i,time)*roi*1)/(time*100);
     }
     for(int i=1;i<=time;i++){
         suminst=suminst+installement(principle,time);
     }
     cout<<" Net Amount                  "<<suminst<<"      "<<sumint<<"    "<<(suminst+sumint)<<endl;
}
// function to calculate installements
double loan::installement(double principle,int time)
{
    double installement=principle/time;
     
    return installement;
}
// return value of balance amount to be paid left after per year
double loan::balance(double principle,double roi,int i,int time)
{
    double inst=installement(principle,time);
    principle+=inst;
    for(int j=0;j<i;j++){
        principle=principle-inst;
    }
         return principle;
}
int main()
{
    //as you tell bank the ammount of loan needed as principle and time required for loan payment bank tell you your total amount paid per year by this program
    double principle;
    cin>>principle;
    double rate;
    cin>>rate;
    int totalmonth;
    cin>>totalmonth;
    cout<<"              Year Wise Statement       "<<endl;
    cout<<"Principle :"<<principle<<endl;
    cout<<"Interest Rate :"<<rate<<endl;
    cout<<"Number of Total years :"<<totalmonth<<endl;
    loan loandisplay;
   loandisplay.display(principle,rate,totalmonth);
 return 0;
}