#include<iostream>
using namespace std;
class GovEmp;
class PrivEmp;
//Author-202101224 SABVA JAY DILIPBHAI
//DATE:26-4-2022    
class Person
{
public:
	int id;
	int cibil_score;
	int month_income;
	int year_of_s;
};

class GovEmp : private Person
{
private:
	bool dis_act;
	int ask;
public:

	/*void setdis_act(bool dis_act)
	{
		dis_act = dis_act;
	}
	bool getdis_act()
	{
		return dis_act;
	}*/

	GovEmp()
	{
		cout << "Enter Your ID:\n";
		cin >> id;
		
		cout << "Enter Your CIBIL Score:(150-900)\n";
		cin >> cibil_score;
		if (cibil_score < 150 || cibil_score>900)
		{
			do
			{
				cout << "Please Enter Between 150-900\n";
				cin >> cibil_score;
			} while (cibil_score < 150 || cibil_score>900);
		}

		cout << "Enter Your Monthly Income:\n";
		cin >> month_income;

		cout << "Enter Year Of Remaining Service:\n";
		cin >> year_of_s;

		cout << "Is Any Disciplinary Action Taken Against You:\nFor Yes Enter 1\nFor No Enter 0\nPlease Do Not Number Any Other Than 0 Or 1\n";
		cin >> dis_act;
		
	}
	friend void LoanGrant(GovEmp g1, GovEmp g2, PrivEmp p1, PrivEmp p2, int check);

};

class PrivEmp : private Person
{
private:
	int rating;
	int ask;
public:
	/*void rating(int rating)
	{
		rating = rating;
	}
	bool getrating()
	{
		return rating;
	}*/

	PrivEmp()
	{
		cout << "Enter Your ID:\n";
		cin >> id;

		cout << "Enter Your CIBIL Score Between (150-900)\n";
		cin >> cibil_score;
		if (cibil_score < 150 || cibil_score>900)
		{
			do
			{
				cout << "Please Enter Between 150-900\n";
				cin >> cibil_score;
			} while (cibil_score < 150 || cibil_score>900);
			
		}

		cout << "Enter Your Monthly Income:\n";
		cin >> month_income;

		cout << "Enter Year Of Remaining Service:\n";
		cin >> year_of_s;

		cout << "What Are Your Rating(0-4)\n";
		cin >> rating;
		if (rating < 0 || rating>4)
		{
			cout << "Please Enter Between 0-4\n";
			cin >> rating;
			do
			{
				cout << "Please Enter Between 0-4\n";
				cin >> rating;
			} while (rating < 0 || rating>4);
		}

	}
	friend void LoanGrant(GovEmp g1, GovEmp g2, PrivEmp p1, PrivEmp p2, int check);

};

void LoanGrant(GovEmp g1, GovEmp g2, PrivEmp p1, PrivEmp p2, int check)
{
	/*cout << "G1:For Individual Loan Press 0\nFor Joint Loan Press 1\n";
	cin >> g1.ask;
	cout << "G2:For Individual Loan Press 0\nFor Joint Loan Press 1\n";
	cin >> g2.ask;
	cout << "P1:For Individual Loan Press 0\nFor Joint Loan Press 1\n";
	cin >> p1.ask;
	cout << "P2:For Individual Loan Press 0\nFor Joint Loan Press 1\n";
	cin >> p2.ask;*/

	g1.ask = check;
	g2.ask = check;
	p1.ask = check;
	p2.ask = check;

	if (g1.ask == 0)
	{

		if (g1.dis_act == 0 && g1.month_income >= 50000 && g1.year_of_s >= 20 && g1.cibil_score >= 350)
		{
			cout << "Congratulation G1 You Are Eligable For Loan Of 10Lakh INR\n";
		}
		else if (g1.dis_act == 0 && g1.month_income >= 25000 && g1.year_of_s >= 15 && g1.cibil_score >= 200)
		{
			cout << "Congratulation G1 You Are Eligable For Loan Of 5Lakh INR\n";
		}
		else
		{
			cout << "Sorry G1 You Are Not Eligable For Individual Loan\n";
		}
		cout << "\n";
	}

	if (g2.ask == 0)
	{
	
		if (g2.dis_act == 0 && g2.month_income >= 50000 && g2.year_of_s >= 20 && g2.cibil_score >= 350)
		{
			cout << "Congratulation G2 You Are Eligable For Loan Of 10Lakh INR\n";
		}
		else if (g2.dis_act == 0 && g2.month_income >= 25000 && g2.year_of_s >= 15 && g2.cibil_score >= 200)
		{
			cout << "Congratulation G2 You Are Eligable For Loan Of 5Lakh INR\n";
		}
		else
		{
			cout << "Sorry G2 You Are Not Eligbile For Individual Loan\n";
		}
		cout << "\n";
	}

	if (p1.ask == 0)
	{
		
		if (p1.rating >= 0 && p1.month_income >= 50000 && p1.year_of_s >= 20 && p1.cibil_score >= 350)
		{
			cout << "Congratulation P1 You Are Eligable For Loan Of 10Lakh INR\n";
		}
		else if (p1.rating >= 0 && p1.month_income >= 25000 && p1.year_of_s >= 15 && p1.cibil_score >= 200)
		{
			cout << "Congratulation P1 You Are Eligable For Loan Of 5Lakh INR\n";
		}
		else
		{
			cout << "Sorry P1 You Are Not Eligbile For Individual Loan\n";
		}
		cout << "\n";

	}

	if (p2.ask == 0)
	{
		
		if (p2.rating >= 3 && p2.month_income >= 70000 && p2.year_of_s >= 20 && p2.cibil_score >= 350)
		{
			cout << "Congratulation P2 You Are Eligable For Loan Of 10Lakh INR\n";
		}
		else if (p2.rating >= 3 && p2.month_income >= 35000 && p2.year_of_s >= 15 && p2.cibil_score >= 250)
		{
			cout << "Congratulation P2 You Are Eligable For Loan Of 5Lakh INR\n";
		}
		else
		{
			cout << "Sorry P2 You Are Not Eligbile For Individual Loan\n";
		}
		cout << "\n";

	}

	if (p1.ask == 1)
	{
		if (g1.dis_act == 0 && p1.rating >= 3)
		{

			if (g1.month_income + p1.month_income >= 100000 && g1.year_of_s + p1.year_of_s >= 40)
			{
				cout << "Congratulation G1 And P1 You Are Eligible For Loan Of 10 Lakh INR\n";
			}
			else if (g1.month_income + p1.month_income >= 50000 && g1.year_of_s + p1.year_of_s >= 30)
			{
				cout << "Congratulation G1 And P1 You Are Eligible For Loan Of 5 Lakh INR\n";
			}
			
			else
			{
				cout << "Sorry G1 And P1 You Are Not Eligible For Joint Loan\n";
			}
		}
		else
		{
			cout << "Sorry G1 And P1 You Are Not Eligible For Joint Loan\n";
		}
		cout << "\n";
	}

	if (g1.ask == 1)
	{
		if (g1.dis_act == 0 && p2.rating >= 3)
		{

			if (g1.month_income + p2.month_income >= 100000 && g1.year_of_s + p2.year_of_s >= 40)
			{
				cout << "Congratulation G1 And P2 You Are Eligible For Loan Of 10 Lakh INR\n";
			}
			else if (g1.month_income + p2.month_income >= 50000 && g1.year_of_s + p2.year_of_s >= 30)
			{
				cout << "Congratulation G1 And P2 You Are Eligible For Loan Of 5 Lakh INR\n";
			}
			else
			{
				cout << "Sorry G1 And P2 You Are Not Eligible For Joint Loan\n";
			}
		}
		else
		{
			cout << "Sorry G1 And P2 You Are Not Eligible For Joint Loan\n";
		}
		cout << "\n";
	}

	if (p2.ask == 1)
	{
		if (g2.dis_act == 0 && p1.rating >= 3)
		{
			if (g2.month_income + p1.month_income >= 100000 && g2.year_of_s + p1.year_of_s >= 40)
			{
				cout << "Congratulation G2 And P1 You Are Eligible For Loan Of 10 Lakh INR\n";
			}
			else if (g2.month_income + p1.month_income >= 50000 && g2.year_of_s + p1.year_of_s >= 30)
			{
				cout << "Congratulation G2 And P1 You Are Eligible For Loan Of 5 Lakh INR\n";
			}
			
			else
			{
				cout << "Sorry G2 And P1 You Are Not Eligible For Joint Loan\n";
			}
		}
		else
		{
			cout << "Sorry G2 And P1 You Are Not Eligible For Joint Loan\n";
		}
		cout << "\n";
	}

	if (g2.ask == 1)
	{
		if (g2.dis_act == 0 && p2.rating >= 3)
		{
			if (g2.month_income + p2.month_income >= 100000 && g2.year_of_s + p2.year_of_s >= 40)
			{
				cout << "Congratulation G2 And P2 You Are Eligible For Loan Of 10 Lakh INR\n";
			}
			else if (g2.month_income + p2.month_income >= 50000 && g2.year_of_s + p2.year_of_s >= 30)
			{
				cout << "Congratulation G2 And P2 You Are Eligible For Loan Of 5 Lakh INR\n";
			}
			else
			{
				cout << "Sorry G2 And P2 You Are Not Eligible For Joint Loan\n";
			}
		}
		else
		{
			cout << "Sorry G2 And P2 You Are Not Eligible For Joint Loan\n";
		}
		cout << "\n";
	}
	cout << "\n";

}

int main()
{
	cout << "Information Of 1st Government Employee\n";
	GovEmp g1 = GovEmp();
	cout << "\n";

	cout << "Information Of 2nd Government Employee\n";
	GovEmp g2 = GovEmp();
	cout << "\n";

	cout << "Information Of 1st Private Employee\n";
	PrivEmp p1 = PrivEmp();
	cout << "\n";

	cout << "Information Of 2nd Private Employee\n";
	PrivEmp p2 = PrivEmp();
	cout << "\n";

	int check;
	cout << "Which Loan Do You want To Take\nFor Individual Loan Press 0\nFor Joint Loan Press 1\n";
	cin >> check;

	if (check != 0 && check != 1)
	{
		cout << "Please Enter 0 Or 1\n";
		cin >> check;
		while (check != 0 && check != 1)
		{
			cout << "Please Enter 0 Or 1\n";
			cin >> check;
		}
	}

	cout<<"\n";
	LoanGrant(g1, g2, p1, p2, check);
	return 0;
}
