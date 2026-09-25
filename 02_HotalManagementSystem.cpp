#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Room{
public:
    int num;
    bool available;

    Room(int num,bool available){
        this->num = num;
        this->available = available;
    }
    Room(int num){
        this->num = num;
        this->available = true;
    }
    Room(){

    }


    
};
class Customer{
public:
    string name;
    int age;
    int number;
    int Id;
    bool available;

    Customer(string name, int age, int number, int Id, bool available){
        this->name = name;
        this->age = age;
        this->number = number;
        this->Id = Id;
        this->available = available;
    }

    Customer(string name, int age, int number, int Id){
        this->name = name;
        this->age = age;
        this->number = number;
        this->Id = Id;
        this->available = true;
    }
};


class Hotel{
private:
    vector<Room>Rooms;
    vector<Customer>Customers;

public:
    void addRoom(){
      int num;

        cout << "Enter the Room Number: ";
        cin >> num;

        // Check if room already exists
        for (const Room& room : Rooms) {
            if (room.num == num) {
                cout << "Room already exists!\n";
                return;
            }
        }

        Rooms.push_back(Room(num));

        cout << "Room added successfully!\n";
    }
    void bookingRoom(){
        int Id,number,age,roomnum;
        string name;
        
        cout<<"Enter Age :";
        cin>>age;
        cout<<"Enter mobile number :";
        cin>>number;
        cout<<"Enter Id number :";
        cin>>Id;
        cout<<"Enter Room number :";
        cin>>roomnum;
        cin.ignore();
        cout<<"Enter Customer Name :";
        getline(cin,name);
        
        for(Room& room : Rooms){
            if(room.num==roomnum){
                
                Rooms.pop_back();
                cout<<"Room is book succesfully"<<endl;
                return;
            }
        }
        
    
    }
    

    //DISPLAY ROOM
    void DisplayRoom(){
        if(Rooms.empty()){
            cout<<"No Room Available!";
        }
        for(Room& room : Rooms){
            cout<<"\n Room : "<<room.num<<endl;

            if(room.available){
                cout<<"Status : Available"<<endl;

            }else{
                cout<<"Status : Not Available!"<<endl;
            }
        }
        cout<<endl;
    }

    void SearchRoom(){
        int num;

        cout<<"Enter Room number :";
        cin>>num;

        for(Room& room: Rooms){
            if(room.num==num){
                cout<<"Room is Available"<<endl;
                return;
            }
            cout<<"Room is not available";
        }
    }

    void addCustomer(){
        int Id,number,age;
        string name;

        cout<<"Enter Age :";
        cin>>age;
        cout<<"Enter mobile number :";
        cin>>number;
        cout<<"Enter Id number :";
        cin>>Id;
        cin.ignore();
        cout<<"Enter Customer Name :";
        getline(cin,name);
        for(Customer& customer : Customers){
            if(customer.Id==Id){
                cout<<"Customer is already exit\n";
                return;
            }
            
        Customers.push_back(Customer(name,age,number,Id));
        cout<<"Customer already exit \n";
        }

    }

    void searchCustomer(){
        int Id;

        cout<<"Enter customer ID number :";
        cin>>Id;
        cout<<endl;

        for(const Customer& customer : Customers){

            if(customer.Id==Id){
                cout<<"customer name : "<<customer.name<<endl;
                cout<<"customer age : "<<customer.age<<endl;
                cout<<"customer mobile number :"<<customer.number<<endl;
                cout<<"customer Id : "<<customer.Id<<endl;
                for(const Room& room : Rooms){
                    cout<<"Room number : "<<room.num<<endl;
                }
                
            }
            else{
                cout<<"Not customer found";
            }
        }
    }

    void Displaycustomer(){
        if(Customers.empty()){
            cout<<"No customer available";
        }
        for(Customer& customer : Customers){
            cout<<"customer name : "<<customer.name<<endl;
            cout<<"customer age : "<<customer.age<<endl;
            cout<<"customer mobile number :"<<customer.number<<endl;
            cout<<"customer Id : "<<customer.Id<<endl;
            if(customer.available){
                cout<<"Status: Available";
            }else{
                cout<<"customer not available";
            }
        }
    }
    void Availability(){
        for(Room& room : Rooms){
            if(room.available){
                cout<<"Available Room :"<<room.num;
            }else{
                cout<<"Rooms Are not available ";
            }
        }
    }
    void calculateCharge(){
        int RoomRent = 50000,FoodCharge = 2000,ServiceCharge = 500; 

        int day,time;

        cout<<"how many days did customer saty :";
        cin>>day;
        cout<<"How many time did customer food order : ";
        cin>>time;

        cout<<endl<<endl;
        cout<<"        CHARGES   ";
        cout<<"Room rent = 50000"<<endl;
        cout<<"how many days did you saty = "<<day<<endl<<endl;
        cout<<"Food charge = 2000"<<endl;
        cout<<"how many time did you Food Order = "<<time<<endl<<endl;
        cout<<"Service charge = 200"<<endl;
        cout<<"Service time = "<<time<<endl<<endl;
        cout<<     "Room rent = "<<RoomRent*day<<endl;
        cout<<"   Food charge = "<<FoodCharge*time<<endl;
        cout<<"Service charge = "<<ServiceCharge*time<<endl;
        cout<<"             ___________"<<endl;
        cout<<"         Total = "<<(RoomRent*day)+(FoodCharge*time)+(ServiceCharge*time)<<endl;

    }
    void ReleaseRoom(){
        int Id,roomnum;
        
        cout<<"Enter Id number :";
        cin>>Id;    
        cout<<"Enter Room number :";
        cin>>roomnum;
        for(Room& room: Rooms){
            if(room.num!=roomnum){
                Rooms.push_back(roomnum);
            }
            cout<<"Room succesfully released"<<endl;
        }
        cout<<"Invalid Room number"<<endl;
    }
    
};



int main(){
    int choice;
    
    Hotel h;
    do
    {
    cout<<endl;
    cout<<"=================================\n";
    cout<<"  Hotal management systam"<<endl;
    cout<<"=================================\n";

    cout<<"1. Add the Room             6. Add Customer"<<endl;
    cout<<"2. Display Room             7. Search Customer"<<endl;
    cout<<"3. Search Room              8. Display Customer"<<endl;
    cout<<"4. Available Room           9. Calculate charge"<<endl;
    cout<<"5. Booking Room             10. Release Room\n\n\n";
    
    cout<<"Enter your choice : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        h.addRoom();
        break;
    case 2:
        h.DisplayRoom();
        break;
    case 3:
        h.SearchRoom();
        break;
    case 4:
        h.Availability();
        break;
    case 5:
        h.bookingRoom();
        break;
    case 6:
        h.addCustomer();
        break;
    case 7:
        h.searchCustomer();
        break;
    case 8:
        h.Displaycustomer();
        break;
    case 9:
        h.calculateCharge();
        break;
    case 10:
        h.ReleaseRoom();
        break;
        
    default:
        cout<<"Invalid selectiion";
        break;
    }


        
    } while (choice!=10);
    
}