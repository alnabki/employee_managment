#include <string>
#include <database.h>
#include <task.h>
using namespace std;

// gab
void SetAdmin(string employeeId){
    Database db;
    db.setAdmin(employeeId);
    db.close();
}
void SetEmployeTask(){
    Database db;
    Task t;
    Employee e;
    db.selectTasks();
    t.enterId();
    db.selectTask(t.id);
    e.enterId();
    db.setEmployeTask(t.id, e.id);
    db.close();
}

bool IsAdmin(string employeeId){
    Database db;
    bool is = db.isAdmin(employeeId);    db.close();
    return is;
}


//Task ONLY
void selectTask(string taskId)
{
    Task t;
    Database db;
    t = db.selectTask(taskId);
    t.show();
}

void insertTask(string ProjectId)
{
    Task t;
    Database db;
    t.enter();
    t.status = "New";
    t.projectId = ProjectId;
    db.insertTask(t);
}
void deleteTask(string taskId)
{
    Database db;
    db.deleteTask(taskId);
}
void updateTask()
{
    Task t;
    Database db;
    t.enterId();
    t.enter();
    db.updateTask(t);
}

void startTask(string TId, string EId){
    Database db;
    db.startTask(TId, EId);
}

void pauseTask(string id){
    Database db;
    db.pauseTask(id);
}

void endTask(string id){
    Database db;
    db.endTask(id);
}


//Task End

//Project ONLY
void insertProject()
{
    Project p;
    Database db;
    p.enter();
    p.status = "new";
    db.insertProject(p);
}

void deleteProject(string id)
{
    Database db;
    db.deleteProject(id);
}

void updateProject()
{
    Project p;
    Database db;
    p.enterId();
    p.enter();
    db.updateProject(p);
}
//Project End

void createDatabase(){
    Database db;
    db.createDatabase();

}


// end gab

// mazen
    string longToString(long  number){
        std::stringstream ss;
        ss << number;
        return ss.str();
    }
    long stringToLong(string str){
        return atol(str.c_str());
     }
// end mazen

// MOHAMAD

    void showEmployee(){

        Employee e;
        Database db;
        list<Employee> employess;
        cout <<" __________________________________________________________________________________________________________________________________"<<endl;
        cout <<"|                                                      Employee's details                                                          |"<<endl;
        cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
        cout <<"|"<<setw(10)<<"id"<<setw(20)<<"Name"<<setw(30)<<"Email"<<setw(20)<<"Password"<<setw(30)<<"Address"<<setw(20)<<"Phone"<<"|"<< endl;
        employess = db.selectEmployees();
        for ( e : employess){
            cout <<"|"<<setw(10)<<e.id<<setw(20)<<e.name<<setw(30)<<e.email<<setw(20)<<e.password<<setw(30)<<e.address<<setw(20)<<e.phone<<"|"<<endl;
        }
        cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showDays( long date1, long date2,string id){
         Employee e;
        Day d;
        Database db;
        int sum=0;
        cout <<" ________________________________________________________________________________"<<endl;
        cout <<"|                       Days's details for Employee                              |"<<endl;
        cout <<"|________________________________________________________________________________|"<<endl;
        cout <<"|"<<setw(18)<<"Date"<<setw(23)<<"startTime"<<setw(18)<<"endTime"<<setw(18)<<"timeSpend"<<setw(4)<<"  |"<< endl;
        list<Day> days;
        days = db.selectEmployeesWorkForPeriod(date1,date2,id);
        for ( d : days){
            CustomTime c1 =CustomTime(d.date),c2=CustomTime(d.start),c3=CustomTime(d.endTime);
            cout <<"|"<<setw(20)<<c1.date()<<setw(20)<<c2.Time()<<setw(20)<<c3.Time()<<setw(15)<<d.timeSpend<<setw(6)<<" |"<<endl;
            sum = sum + d.timeSpend;
        }
        cout <<"|________________________________________________________________________________|"<<endl;
        cout <<"|   the total timeSpend for this period  is =\t "<<setw(17)<<sum<<setw(16)<<"|"<<endl;
        cout <<"|________________________________________________________________________________|"<<endl;
    }

    void showTimeOff(string id){
        Database db;
        TimeOff timeOf;
        list<TimeOff> timesOff;

        cout <<" ___________________________________________________________"<<endl;
        cout <<"|                       Your TimesOff                       |"<<endl;
        cout <<"|___________________________________________________________|"<<endl;
        cout <<"|"<<setw(15)<<"From"<<setw(30)<<"To"<<setw(15)<<"|"<< endl;
        cout <<"|___________________________________________________________|"<<endl;
        int i=0;
        long matrix[100][100];
        long temp,temp1,temp2;
        timesOff = db.selectTimesOff(id);
        for ( timeOf : timesOff){
             matrix[i][0]=timeOf.from;
             matrix[i][1]=timeOf.to;
             ++i;
        }
        for (int m=0;m<i;m++){
            for(int j=1;j<=i;j++){
                if (matrix[m][0]>matrix[j][0]){
                    temp=matrix[m][0];
                    matrix[m][0]=matrix[j][0];
                    matrix[j][0]=temp;
                    temp1=matrix[m][1];
                    matrix[m][1]=matrix[j][1];
                    matrix[j][1]=temp1;
                }
             }
        }
        for (int k=1;k<=i;++k){
            CustomTime c1 =CustomTime(matrix[k][0]),c2=CustomTime(matrix[k][1]);
            cout <<"|"<<setw(10)<<c1.date()<<"  "<<setw(10)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(10)<<c2.Time()<<setw(6)<<"|"<<endl;
    }
        cout <<"|___________________________________________________________|"<<endl;
    }

    void showTimesOffWithId(string id){
        Day d;
        Database db;
        TimeOff timeOf;
        list<TimeOff> timesOff;
        cout <<" _____________________________________________________________________"<<endl;
        cout <<"|                               Your TimesOff                         |"<<endl;
        cout <<"|_____________________________________________________________________|"<<endl;
        cout <<"|"<<setw(5)<<"ID"<<setw(18)<<"From"<<setw(32)<<"To"<<"              |"<< endl;
        cout <<"|_____________________________________________________________________|"<<endl;
        int i=0;
        long matrix[100][100];
        long temp,temp1,temp2;
        timesOff = db.selectTimesOff(id);
        for ( timeOf : timesOff){
             matrix[i][0]=d.stringToLong(timeOf.id);
             matrix[i][1]=timeOf.from;
             matrix[i][2]=timeOf.to;
             ++i;
        }
        for (int m=0;m<i;m++){
            for(int j=1;j<=i;j++){
                if (matrix[m][1]>matrix[j][1]){
                    temp=matrix[m][1];
                    matrix[m][1]=matrix[j][1];
                    matrix[j][1]=temp;
                    temp1=matrix[m][0];
                    matrix[m][0]=matrix[j][0];
                    matrix[j][0]=temp1;
                    temp2=matrix[m][2];
                    matrix[m][2]=matrix[j][2];
                    matrix[j][2]=temp2;
                }
             }
        }
        for (int k=1;k<=i;++k){
             CustomTime c1 =CustomTime(matrix[k][1]),c2=CustomTime(matrix[k][2]);
             cout <<"|"<<setw(5)<<matrix[k][0]<<setw(15)<<c1.date()<<"  "<<setw(6)<<c1.Time()<<setw(24)<<c2.date()<<"  "<<setw(6)<<c2.Time()<<setw(10)<<"|"<<endl;
        }
        cout <<"|_____________________________________________________________________|"<<endl;
    }

    void  showTaskForEmployee(string employeeId){
        Task t;
        Day d;
        Database db;
        list<Task> tasks;
        cout <<"+------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
        cout <<"|                                                        Your Tasks                                                                                    |"<<endl;
        cout <<"+------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
        cout <<"|"<<setw(10)<<"Title"<<setw(10)<<"Status"<<setw(20)<<"StartTemp"<<setw(30)<<"EndTemp"<<setw(25)<<"TimeSpend"<<setw(30)<<"ProjectId"<<setw(26)<<"|"<< endl;
        cout <<"|______________________________________________________________________________________________________________________________________________________|"<<endl;

        tasks = db.selectEmployeeTasks(employeeId);
        for ( t : tasks){
               long startTemp=d.stringToLong(t.startTemp),endTemp=d.stringToLong(t.endTemp);
            CustomTime c1 =CustomTime(startTemp),c2=CustomTime(endTemp);
            cout <<"|"<<setw(10)<<t.title<<setw(10)<<t.status<<setw(15)<<c1.date()<<"  "<<setw(8)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(8)<<c2.Time()<<setw(16)<<t.timeSpend<<setw(30)<<t.projectId<<setw(30)<<"|"<< endl;
        }
        cout <<"|______________________________________________________________________________________________________________________________________________________|"<<endl;

    }
    void insertTimeOff(TimeOff timeOf){
        Database db;
        db.insertTimeOff(timeOf);
    }
    TimeOff selectTimeOff(string id){
        TimeOff timeOf;
        Database db;
        timeOf=db.selectTimeOff(id);
        return timeOf;
    }

    void updateTimeOff(TimeOff timeOf){
        Database db;
        db.updateTimeOff(timeOf);
    }
    void deleteTimeOff(string id){
        Database db;
        db.deleteTimeOff(id);
    }
    void insertEmployee(){
        Employee e;
        e.enter();
        Database db;
        db.insertEmployee(e);
        e=db.selectEmployeeByEmail(e.email);
	    e.show();
    }
    Employee selectEmployeeByEmail(string email){
        Database db;
        Employee e;
        e=db.selectEmployeeByEmail(email);
        return e;
    }
    Employee selectEmployeeById(string id){
        Database db;
        Employee e;
        e=db.selectEmployeeById(id);
        return e;
    }
    void updateEmployee(){
        Employee e;
        Database db;
        showEmployee();
        e.enterId();
        e=selectEmployeeById(e.id);
        e.show();
        cout <<" ________________________"<<endl;
        cout <<"|    enter new details   |"<<endl;
        cout <<"|________________________|"<<endl;
        e.enter();
        db.updateEmployee(e);
    }
    void deleteEmployee(){
        Database db;
        Employee e;
        showEmployee();
        e.enterId();
        e=selectEmployeeById(e.id);
        e.show();
        cout <<" __________________________"<<endl;
        cout <<"|  are you sure press Y/N  |"<<endl;
        cout <<"|__________________________|"<<endl;
        string  choice;
        cin>>choice ;
        if (choice=="y" || choice=="Y"){
        db.deleteEmployee(e.id);
        }
    }

  //end MOHAMAD.
