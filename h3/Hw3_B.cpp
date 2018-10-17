/**
 PART B:
 
 A movie theater keeps 20 percent of the gross box office profit.  The remainder goes to the
 movie distributor. Write a program that calculates a theater’s gross and net box office profit
 for a night and one movie. The price of an adult ticket is $10.00 and a child’s ticket is
 $6.00. The program asks for the name of the movie, and how many adult and child tickets were
 sold, calculates the gross box office profit, the net box office profit, the amount paid to
 the distributor, and displays a report.
 
 Brian Le
 Unix
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double ADULT_TICKET = 10.00;
const double CHILD_TICKET = 6.00;

int main()
{
    int num_adult_tickets,
        num_child_tickets;
    double adult_total,
           child_total,
           gross_profit,
           net_profit, 
           amount_paid; 
    string movie_name;
    
    //user input
    cout << "What is the name of the movie? ";
    getline(cin, movie_name);

    cout << "How many adult tickets were sold? ";
    cin >> num_adult_tickets;

    cout << "How many child tickets were sold? ";
    cin >> num_child_tickets;

    //calculations
    adult_total = num_adult_tickets * ADULT_TICKET;
    child_total = num_child_tickets * CHILD_TICKET;
    gross_profit = adult_total + child_total;
    net_profit = 0.2 * gross_profit;
    amount_paid = gross_profit - net_profit;

    //output
    cout << endl;
    
    cout << "Movie Name:" << setw(18) << "\"" << movie_name << "\"" << endl;
    
    cout << setprecision(2) << fixed;
    
    cout << "Adult Tickets (" << num_adult_tickets << "):" << setw(15)
         << "$" << setw(8) << adult_total << endl; 
    
    cout << "Child Tickets (" << num_child_tickets << "):" << setw(15)
         << "$" << setw(8) << child_total << endl;
    
    cout << "Gross Box Office Movie Profit:" << setw(5)
         << "$" << setw(8) << gross_profit << endl;
    
    cout << "Net Box Office Profit:" << setw(13)
         << "$" << setw(8) << net_profit << endl;
    
    cout << "Amount Paid to Distributor:" << setw(8)
         << "$" << setw(8) << amount_paid << endl;
    
    return 0;
}
/***********************************************************************
What is the name of the movie? Star Wars: The Force Awakens
How many adult tickets were sold? 382
How many child tickets were sold? 127

Movie Name:                 "Star Wars: The Force Awakens"
Adult Tickets (382):              $ 3820.00
Child Tickets (127):              $  762.00
Gross Box Office Movie Profit:    $ 4582.00
Net Box Office Profit:            $  916.40
Amount Paid to Distributor:       $ 3665.60



*/


/***********************************************************************
What is the name of the movie? The Good Dinosaur
How many adult tickets were sold? 100
How many child tickets were sold? 200

Movie Name:                 "The Good Dinosaur"
Adult Tickets (100):              $ 1000.00
Child Tickets (200):              $ 1200.00
Gross Box Office Movie Profit:    $ 2200.00
Net Box Office Profit:            $  440.00
Amount Paid to Distributor:       $ 1760.00
 

*/
