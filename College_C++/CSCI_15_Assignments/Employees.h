
using namespace std;

class Employee
{
    protected:
    string Employee_ID;
    float Hours;
    float Pay_Per_Hour;
    float Income_Tax_Rate;
    float Over_time_hours;
    string Employee_Status; //(string such as Hourly, Salaried, Contractor)

    public:
    Employee()
    {
        Employee_ID = "N/A";
        Hours = 0;
        Pay_Per_Hour = 0;
        Income_Tax_Rate = 0;
        Employee_Status = "N/A";
    }
    void SetID(string ID)
    {
        Employee_ID = ID;
    }
    void SetHours(float hours)
    {
        Hours = hours;
    }
    void SetPay(float payrate)
    {
        Pay_Per_Hour = payrate;
    }
    void SetTaxRate(float taxrate)
    {
        Income_Tax_Rate = taxrate;
    }
    void SetStatus(string status)
    {
        Employee_Status = status;
    }
    string getID()
    {
        return Employee_ID;
    }
    float getHours()
    {
        return Hours;
    }
    float getPay()
    {
        return Pay_Per_Hour;
    }
    string getStatus()
    {
        return Employee_Status;
    }

    //Pure virtual (just a redirector)
    virtual void terminate() = 0;
    virtual void calculatepay() = 0;
    virtual void Display(int n) = 0;
    virtual void setovertime() = 0;
    void Initialize();

};

class Hourly : public Employee
{
    protected:
    float overtimepay = 0;
    float regularpay = 0;
    float grosspay = 0;
    float taxes = 0;
    float netpay = 0;

    public:
    void setovertime()
    {
        if(Hours <= 40)
        {
            Over_time_hours = 0;
        }
        else
        {
            Over_time_hours = Hours - 40;
            Hours = 40;

        }
    }
    void calculatepay()
    {
        overtimepay = (Over_time_hours * Pay_Per_Hour * 1.5);
        regularpay = (Hours * Pay_Per_Hour);
        grosspay = regularpay + overtimepay;
        taxes = grosspay * Income_Tax_Rate;
        netpay = grosspay - taxes;
    }
    void terminate()
    {
        Employee_Status = "Hourly - Terminated";
    }
    void Display(int n)
    {
        cout << "\n\n\tIndex #" << n << " (ID: "<< Employee_ID << ")"
             << "\n\tHours: " << Hours;
        cout << "\n\t" << Employee_Status;
        if(Over_time_hours != 0)
        {
            cout << ", Overtime Hours: " << Over_time_hours;
        }
        cout << "\n\tPay Rate: $" << Pay_Per_Hour;
        if(Over_time_hours != 0)
        {
            cout << ", Overtime Pay Rate: $" << (Pay_Per_Hour*1.5);
        }
        cout << "\n\tTax Rate: " << Income_Tax_Rate*100 << "%";
        cout << "\n\tNet Pay: $" << netpay;

    }
    void Initialize(string ID, float hours, float payrate, float taxrate, string status)
    {
        Employee_ID = ID;
        Hours = hours;
        Pay_Per_Hour = payrate;
        Income_Tax_Rate = taxrate;
        Employee_Status = status;
    }

};

class Salaried : public Hourly
{
    public:
    void calculatepay()
    {
        grosspay = Pay_Per_Hour;
        taxes = grosspay * Income_Tax_Rate;
        netpay = grosspay - taxes;
    }
    void terminate()
    {
        Employee_Status = "Salaried - Terminated";
    }
    void setovertime()
    {
        Over_time_hours = 0;
    }
    void Display(int n)
    {
        cout << "\n\n\tIndex #" << n << " (ID: "<< Employee_ID << ")";
        cout << "\n\t" << Employee_Status;
        cout << "\n\tAnnual Salary: " << Pay_Per_Hour
             << "\n\tTax Rate: " << Income_Tax_Rate*100 << "%"
             << "\n\tNet Pay: $" << netpay;
    }
    void Initialize(string ID, float payrate, float taxrate, string status)
    {
        Employee_ID = ID;
        Pay_Per_Hour = payrate;
        Income_Tax_Rate = taxrate;
        Employee_Status = status;
    }

};

class Contractor : public Employee
{
    private:
    int grosspay;

    public:
    void calculatepay()
    {
        grosspay = Pay_Per_Hour;
    }
    void terminate()
    {
        Employee_Status = "Contract Ended";
    }
    void setovertime()
    {
        Over_time_hours = 0;
    }
    void Display(int n)
    {
        cout << "\n\n\tIndex #" << n << " (ID: "<< Employee_ID << ")";
        cout << "\n\t" << Employee_Status;
        cout << "\n\tContractor Fee: $" << grosspay;
    }
    void Initialize(string ID, float payrate, string status)
    {
        Employee_ID = ID;
        Pay_Per_Hour = payrate;
        Employee_Status = status;
    }
};

void Menu()
{
    cout << "\n\t1 - Enter Data for Hourly Employees"
                 << "\n\t2 - Enter Data for Salaried Employees"
                 << "\n\t3 - Enter Data for Contractor Personnel"
                 << "\n\t4 - Display Data for Hourly Employees"
                 << "\n\t5 - Display Data for Salaried Employees"
                 << "\n\t6 - Display Data for Contractor Personnel"
                 << "\n\t7 - Terminate an Hourly Employee - set Employee Status to \"Hourly - Terminated\""
                 << "\n\t8 - Terminate a Salaried Employee - set Employee Status to \"Salaried - Terminated\""
                 << "\n\t9 - Terminate a Contractor - set Employee Status to \"Contract Ended\""
                 << "\n\t10 - Quit"
                 << "\n\n\tEnter Option (1-10): ";
}
