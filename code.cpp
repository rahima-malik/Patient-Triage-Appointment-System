#include <iostream>
#include <string>
using namespace std;
// ABSTRACT BASE CLASS (ABSTRACTION)
class Patient
{
protected:
    int patientID;
    string name;
    int age;
    string medicalCondition;
    int severity;
    int arrivalOrder;
public:
    // Constructor
    Patient(int id, string n, int a,
            string condition, int sev, int arrival)
    {
        patientID = id;
        name = n;
        age = a;
        medicalCondition = condition;
        severity = sev;
        arrivalOrder = arrival;
    }
    // Pure Virtual Function
    virtual string getPatientType() = 0;
    // Virtual Function (Polymorphism)
    virtual void display()
    {
        cout << "\nPatient ID      : " << patientID;
        cout << "\nName            : " << name;
        cout << "\nAge             : " << age;
        cout << "\nCondition       : " << medicalCondition;
        cout << "\nPriority Level  : " << severity;
        cout << "\nArrival Order   : " << arrivalOrder;
    }
    int getSeverity()
    {
        return severity;
    }
    int getArrivalOrder()
    {
        return arrivalOrder;
    }
    virtual ~Patient() {}
};
// GENERAL PATIENT CLASS (INHERITANCE)
// Automatically gets priority 1
class GeneralPatient : public Patient
{
public:
    GeneralPatient(int id, string n, int a,
                   string condition, int arrival)

        : Patient(id, n, a, condition, 1, arrival)
    {
    }
    string getPatientType()
    {
        return "General Patient";
    }
};
// EMERGENCY PATIENT CLASS (INHERITANCE)
// Automatically gets priority 3
class EmergencyPatient : public Patient
{
public:
    EmergencyPatient(int id, string n, int a,
                     string condition, int arrival)

        : Patient(id, n, a, condition, 3, arrival)
    {
    }
    string getPatientType()
    {
        return "Emergency Patient";
    }
};
// CRITICAL PATIENT CLASS (INHERITANCE)
// Automatically gets priority 5
class CriticalPatient : public Patient
{
public:
    CriticalPatient(int id, string n, int a,
                    string condition, int arrival)

        : Patient(id, n, a, condition, 5, arrival)
    {
    }
    string getPatientType()
    {
        return "Critical Patient";
    }
};
// MAIN FUNCTION
int main()
{
    // Array of patient pointers
    Patient* queue[100];
    int count = 0;
    int arrivalCounter = 1;
    int choice;
    do
    {
        cout << "\n====================================";
        cout << "\n PATIENT TRIAGE & APPOINTMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Patient";
        cout << "\n2. View Waiting Queue";
        cout << "\n3. Call Next Patient";
        cout << "\n4. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
        // ADD PATIENT
        case 1:
        {
            try
            {
                int id;
                int age;
                int type;
                string name;
                string condition;
                cout << "\nEnter Patient ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Patient Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter Medical Condition: ";
                getline(cin, condition);
                cout << "\nSelect Patient Type";
                cout << "\n1. General Patient";
                cout << "\n2. Emergency Patient";
                cout << "\n3. Critical Patient";
                cout << "\nEnter Type: ";
                cin >> type;
                // Exception Handling
                if(type < 1 || type > 3)
                {
                    throw type;
                }
                // Polymorphism
                if(type == 1)
                {
                    queue[count] =
                    new GeneralPatient(
                    id,name,age,
                    condition,arrivalCounter);
                }
                else if(type == 2)
                {
                    queue[count] =
                    new EmergencyPatient(
                    id,name,age,
                    condition,arrivalCounter);
                }
                else
                {
                    queue[count] =
                    new CriticalPatient(
                    id,name,age,
                    condition,arrivalCounter);
                }
                count++;
                arrivalCounter++;
                // MANUAL SORTING
                // Highest Priority First
                for(int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                        bool swapNeeded = false;
                        if(queue[j]->getSeverity() >
                           queue[i]->getSeverity())
                        {
                            swapNeeded = true;
                        }
                        else if(queue[j]->getSeverity() ==
                                queue[i]->getSeverity())
                        {
                            if(queue[j]->getArrivalOrder() <
                               queue[i]->getArrivalOrder())
                            {
                                swapNeeded = true;
                            }
                        }
                        if(swapNeeded)
                        {
                            Patient* temp = queue[i];
                            queue[i] = queue[j];
                            queue[j] = temp;
                        }
                    }
                }
                cout << "\nPatient Added Successfully!\n";
            }
            catch(int)
            {
                cout << "\nInvalid Patient Type!";
                cout << "\nPlease Enter 1, 2 or 3.\n";
            }
            break;
        }
        // VIEW WAITING QUEUE
        case 2:
        {
            if(count == 0)
            {
                cout << "\nNo Patients In Queue.\n";
            }
            else
            {
                cout << "\n\n===== WAITING QUEUE =====\n";

                for(int i=0;i<count;i++)
                {
                    cout << "\nPosition: " << i + 1;

                    cout << "\nType: "
                         << queue[i]->getPatientType();

                    queue[i]->display();

                    cout << "\n--------------------------\n";
                }
            }
            break;
        }
        // CALL NEXT PATIENT
        case 3:
        {
            if(count == 0)
            {
                cout << "\nNo Patients Waiting.\n";
            }
            else
            {
                cout << "\nNEXT PATIENT\n";
                cout << "\nType: "
                     << queue[0]->getPatientType();
                queue[0]->display();
                delete queue[0];
                // Shift Array Left
                for(int i=0;i<count-1;i++)
                {
                    queue[i] = queue[i+1];
                }
                count--;

                cout << "\n\nPatient Sent To Doctor.\n";
            }
            break;
        }
        //========================================
        // EXIT
        //========================================
        case 4:
        {
            cout << "\nProgram Closed.\n";
            break;
        }
        default:
        {
            cout << "\nInvalid Choice!\n";
        }
        }
    }
    while(choice != 4);
    //========================================
    // MEMORY CLEANUP
    //========================================
    for(int i=0;i<count;i++)
    {
        delete queue[i];
    }
    return 0;
}
