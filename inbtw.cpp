#include <string>
#include <database.h>
#include <task.h>
#include <show.h>
#include <login.h>

using namespace std;

void inbtwShowAllTasks();
void workTimesMenu(string id);

// gab
void SetAdmin(string employeeId){
    Database db;
    db.setAdmin(employeeId);
    db.close();
}
bool IsAdmin(string employeeId){
    Database db;
    bool is = db.isAdmin(employeeId);
    db.close();
    return is;
}
void createDatabase(){
    Database db;
    db.createDatabase();

}

//Task updated by ikram
void inbtwShowTask(string taskId)
{
    Task t;
    Database db;
    t = db.selectTask(taskId);
    t.show();
}
void inbtwInsertTask(string projectId){
    Task t;
    Database db;
    t.enter();
    if (t.check==true){
    t.status = "New";
    t.projectId = projectId;
    db.insertTask(t);
    }
}
void inbtwDeleteTask(string taskId){
    Database db;
    db.deleteTask(taskId);
}
void inbtwUpdateTask(){
    Task t;
    Database db;
    t.enterId();
    if (t.check==true){
    t.enterNewTitle();
    db.updateTask(t);
    }
}
void inbtwShowAllTasks(){
    Database db ;
    Day d;
    CustomTime c1;
    CustomTime c2;
    CustomTime c3;
    list<Task> ts =  db.selectTasks();
    Task t;
    t.header();
    for(t:ts){

        long startTemp=stringToLong(t.started);
        long endTemp=stringToLong(t.finish);
        long timeSpend=stringToLong(t.timeSpend);
        c1 =CustomTime(startTemp);
        c2=CustomTime(endTemp);
        c3=CustomTime(timeSpend);
        if(t.started != "0"){
            t.started =  c1.fullDateTime();
        }
        if(t.finish != "0"){
            t.finish =  c2.fullDateTime();
        }
        if(t.timeSpend != "0"){
           t.timeSpend = c3.timeCorrectH();
        }
        Employee e;
        e=db.selectEmployeeById(t.employeeId);
        t.employeeId=e.name;
        t.show();

    }
}
void signEmployeeToTask(){
    Database db;
    Sugges sg;
    Task t;
    Employee e;
    db.selectTasks();
    t.enterId();
    if (t.check==true){
        db.selectTask(t.id);
        e.enterId();
        if (e.check==true){
           t=db.selectTask(t.id);
           sg.p.id=t.projectId;
           sg.e.id=e.id;
           sg.t.id=t.id;
           db.insertSugges(sg);
           db.close();
        }
    }
}
//end updating

void inbtwStartTask( string taskId,string employeeId){
    Task t;
    Database db;
    Project p;
    Task tas;
    Day d ;
    long sum=0;
       Sugges sg;
       list <Sugges> suggess;
       suggess=db.selectSuggestions();
       for(sg :suggess){
           if (taskId==sg.t.id){
               db.deleteSugges(sg.t.id);
           }
       }
       list<Task> tasks;
       tasks =db.selectTasksByEmployeeId(employeeId);
       for (tas:tasks){
           if (tas.status=="Started" && taskId != tas.id) {
               db.pauseTask(tas.id);
               tas=db.selectTask(tas.id);
           }
            sum=sum+d.stringToLong(tas.timeSpend);
       }
       db.startTask(taskId, employeeId);
       t=db.selectTask(taskId);
       p=db.selectProject(t.projectId);
       p.status="Started";
       p.timeSpend=d.longToString(sum);
      // p.timeSpend=p.timeSpend;
       db.updateProject(p);

}

void inbtwPauseTask(string taskId){
    Database db;
    Task t;
    db.pauseTask(taskId);
    Project p;
    Day d;
    t=db.selectTask(taskId);
    list <Task> tasks;
    long sum=0;
    tasks=db.selectTasksByProjectId(t.projectId);
    for(tas:tasks){
        sum=sum+d.stringToLong(tas.timeSpend);
    }
    p=db.selectProject(t.projectId);
    p.timeSpend=d.longToString(sum);
    p.status="Started";
    db.updateProject(p);

}
void inbtwEndTask(string taskId){
    Database db;
    Task tas;
    Task t;
    Day d;
    Project p;
    db.endTask(taskId);
    t=db.selectTask(taskId);
    list <Task> tasks;
    int i=0,j=0;long sum=0;
    tasks=db.selectTasksByProjectId(t.projectId);
    for(tas:tasks){
        if (tas.status=="Ended"){
            j++;
        }
        i++;
        sum=sum+d.stringToLong(tas.timeSpend);
    }
    p=db.selectProject(t.projectId);
    p.timeSpend=d.longToString(sum);
    if(i==j){
       p.status="Ended";
       db.updateProject(p);
   }
   else{
       p.status="Started";
       db.updateProject(p);
   }

}
//Task End


//Project ONLY

//updated by ikram

void inbtwShowAllProjects(){
    Database db;
    Project p;
    Day d;
    list<Project> projects;
    projects = db.selectProjects();
    p.header();
    for(p:projects){
        long timeSpend=d.stringToLong(p.timeSpend);
        CustomTime c=CustomTime(timeSpend);
        cout <<"|"<<setw(10)<<p.id<<setw(20)<<p.title<<setw(30)<<p.description<<setw(20)<<p.status<<setw(20)<<c.timeCorrectH()<<setw(12)<<"|"<<endl;
        cout <<"|_______________________________________________________________________________________________________________|"<<endl;
    }
    db.close();
}
void inbtwInsertProject(){
    Project p;
    Database db;
    p.enter();
    if (p.check==true){
    p.status = "new";
    p.timeSpend="0";
    db.insertProject(p);
    system("pause");
    }
}
void inbtwDeleteProject(string id){
    Database db;
    db.deleteProject(id);
}
void inbtwUpdateProject(){
    Project p;
    Database db;
    p.enterId();
    if (p.check==true){
       p.enter();
       if (p.check==true){
          db.updateProject(p);
       }
       system("pause");
    }
}
//Project End
//end updating



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
    e.showHeaderWithId();
    employess = db.selectEmployees();
    for ( e : employess){
        e.showDataWithId();
    }
    e.showLineWhitId();
}
void showProjectsWithTasks(string id){
    Task t;
    Employee e;
    Project p;
    Database db;
    Day d;

        list<Task> tasks;
        list<Project> projects;
        tasks=db.selectProjectWithTask();
        projects=db.selectProjects();


       for (p:projects){


            cout <<"+---------------------------------+"<<endl;
            cout <<setw(4)<<"|  Project  =   "<< setw(15)<<p.title<<setw(4)<<"|"<<endl;
            cout <<"+----------------------------------------------------------------------------------+"<<endl;
            cout <<"|                                    Your Tasks                                    |"<<endl;
            cout <<"+----------------------------------------------------------------------------------+"<<endl;
            cout <<"|"<<setw(13)<<"TaskId"<<setw(15)<<"TaskTitle"<<setw(13)<<"Status"<<setw(17)<<"TimeSpend"<<setw(17)<<"employeeName"<<setw(8)<<"|"<< endl;
            cout <<"|__________________________________________________________________________________|"<<endl;


          for ( t : tasks){
                e=db.selectEmployeeById(t.employeeId);
               if (t.status=="New" && (t.employeeId=="0" /*|| t.employeeId==id */) && (t.projectId==p.id)){

                    cout<<"|"<<setw(12)<<t.id<<setw(15)<<t.title<<setw(15)<<t.status<< "\t"<<setw(10)<<'0'<<setw(17)<<e.name<<setw(9)<<"|"<<endl;
                }
               if ( (t.status=="Paused" || t.status=="Started" ||  t.status=="Ended"|| t.status=="New")  && (( t.employeeId==id)&& (t.projectId==p.id)) ){
                long timeSpend=d.stringToLong(t.timeSpend);
                CustomTime c=CustomTime(timeSpend);
                     cout<<"|"<<setw(12)<<t.id<<setw(15)<<t.title<<setw(15)<<t.status<< "\t"<<setw(10)<<c.timeCorrectH()<<setw(17)<<e.name<<setw(9)<<"|"<<endl;
               }
           }


             cout <<"|__________________________________________________________________________________|"<<endl;
    }
    }
void showProjectsWithTasksForAdmin(){
        Task t;
        Employee e;
        Project p;
        Day d;
        Database db;
        list<Task> tasks;
        list<Project> projects;
        tasks=db.selectProjectWithTask();
        projects=db.selectProjects();


       for (p:projects){
            long timeSpend1=d.stringToLong(p.timeSpend);
            CustomTime c1=CustomTime(timeSpend1);
            cout <<"+----------------------------------------------------------------------------+"<<endl;
            cout <<setw(4)<<"| ProjectName :"<< setw(10)<<p.title<<"     |"<<setw(4)<<"  status: "<<p.status<<"        |"<<setw(12)<<"timeSpend="<<c1.timeCorrectH()<<setw(3)<<"|"<<endl;
            cout <<"+----------------------------------------------------------------------------------+"<<endl;
            cout <<"|                                    Your Tasks                                    |"<<endl;
            cout <<"+----------------------------------------------------------------------------------+"<<endl;
            cout <<"|"<<setw(13)<<"TaskId"<<setw(15)<<"TaskTitle"<<setw(13)<<"Status"<<setw(17)<<"TimeSpend"<<setw(17)<<"employeeName"<<setw(8)<<"|"<< endl;
            cout <<"|__________________________________________________________________________________|"<<endl;


          for ( t : tasks){
                e=db.selectEmployeeById(t.employeeId);
               if ( t.projectId==p.id){
                long timeSpend=d.stringToLong(t.timeSpend);
                CustomTime c=CustomTime(timeSpend);
                     cout<<"|"<<setw(12)<<t.id<<setw(15)<<t.title<<setw(15)<<t.status<< "\t"<<setw(10)<<c.timeCorrectH()<<setw(17)<<e.name<<setw(9)<<"|"<<endl;
               }



          }
          cout <<"|__________________________________________________________________________________|"<<endl;
    }
}
void showAllTasksForProject(string id){
    Task t;
    Employee e;
    Project p;
    Day d;
    Database db;
    list<Task> tasks;
    list<Project> projects;
    tasks=db.selectProjectWithTask();
    projects=db.selectProjects();
    for (p:projects){

         if (p.id==id){
             long timeSpend1=d.stringToLong(p.timeSpend);
             CustomTime c1=CustomTime(timeSpend1);
             cout <<"+----------------------------------------------------------------------------+"<<endl;
             cout <<setw(4)<<"| ProjectName :"<< setw(10)<<p.title<<"     |"<<setw(4)<<"  status: "<<p.status<<"        |"<<setw(12)<<"timeSpend="<<c1.timeCorrectH()<<setw(3)<<"|"<<endl;
             cout <<"+----------------------------------------------------------------------------------+"<<endl;
             cout <<"|                                    The Tasks                                     |"<<endl;
             cout <<"|__________________________________________________________________________________|"<<endl;
             cout <<"|"<<setw(13)<<"TaskId"<<setw(15)<<"TaskTitle"<<setw(13)<<"Status"<<setw(17)<<"TimeSpend"<<setw(17)<<"employeeName"<<setw(8)<<"|"<< endl;
             cout <<"|__________________________________________________________________________________|"<<endl;
             for ( t : tasks){
                  e=db.selectEmployeeById(t.employeeId);
                  if ( t.projectId==p.id){
                      long timeSpend=d.stringToLong(t.timeSpend);
                      CustomTime c=CustomTime(timeSpend);
                      cout<<"|"<<setw(12)<<t.id<<setw(15)<<t.title<<setw(15)<<t.status<< "\t"<<setw(10)<<c.timeCorrectH()<<setw(17)<<e.name<<setw(9)<<"|"<<endl;
                  }
             }
             cout <<"|__________________________________________________________________________________|"<<endl;
         }
    }
}
void showDays( long date1, long date2,string id){

    while(date1!=-1 && date2!=-1){
    Employee e;
    Day d;
    Database db;
    int sum=0;
    d.showHeader();
    list<Day> days;
    days = db.selectEmployeesWorkForPeriod(date1,date2,id);
    for ( d : days){
        CustomTime c1 =CustomTime(d.date),c2=CustomTime(d.start),c3=CustomTime(d.endTime),c,c4=CustomTime(d.timeSpend);
        cout <<"|"<<setw(20)<<c1.date()<<setw(20)<<c2.Time()<<setw(20)<<c3.Time()<<setw(15)<<c4.timeCorrectH()<<setw(6)<<" |"<<endl;
        sum = sum + d.timeSpend;
    }
    CustomTime c5 =CustomTime(sum);
    cout <<"|________________________________________________________________________________|"<<endl;
    cout <<"|   the total timeSpend for this period  is =\t "<<setw(17)<<c5.timeCorrectH()<<setw(16)<<"|"<<endl;
    cout <<"|________________________________________________________________________________|"<<endl;
    date1=-1;
    date2=-1;
    }
}
void showTimeOff(string id){
    Database db;
    TimeOff timeOf;
    list<TimeOff> timesOff;
    timeOf.showHeaderWithout();
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
    timeOf.showHeaderWithId();
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
         cout <<"|"<<setw(5)<<matrix[k][0]<<setw(15)<<c1.date()<<"  "<<setw(10)<<c1.Time()<<setw(24)<<c2.date()<<"  "<<setw(10)<<c2.Time()<<setw(8)<<"|"<<endl;
    }
    cout <<"|___________________________________________________________________________|"<<endl;
}
void showTaskForEmployee(string employeeId){
    Task t;
    Day d;
    Database db;
    list<Task> tasks;
    t.showHeaderWithoutId();
    tasks = db.selectEmployeeTasks(employeeId);
    for ( t : tasks){
      // long startTemp=d.stringToLong(t.timeTemp),endTemp=d.stringToLong(t.finish);
       //CustomTime c1 =CustomTime(startTemp),c2=CustomTime(endTemp);
       //cout <<"|"<<setw(10)<<t.title<<setw(10)<<t.status<<setw(15)<<c1.date()<<"  "<<setw(8)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(8)<<c2.Time()<<setw(16)<<t.timeSpend<<setw(30)<<t.projectId<<setw(30)<<"|"<< endl;
        long startTemp=d.stringToLong(t.started);
        long endTemp=d.stringToLong(t.finish);
        long timeSpend=d.stringToLong(t.timeSpend);
        CustomTime c1 =CustomTime(startTemp);
        CustomTime c2=CustomTime(endTemp);
        CustomTime c3=CustomTime(timeSpend);
        if(t.started != "0"){
            t.started =  c1.fullDateTime();
        }
        if(t.finish != "0"){
            t.finish =  c2.fullDateTime();
        }
        if(t.timeSpend != "0"){
            t.timeSpend = c3.timeCorrectH();
        }
        cout <<"|"<<setw(15)<<t.title<<setw(10)<<t.status<<setw(15)<<c1.date()<<"  "<<setw(8)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(8)<<c2.Time()<<setw(16)<<t.timeSpend<<setw(30)<<t.projectId<<setw(30)<<"|"<< endl;
        t.showLineWithoutId();
        //t.show();
    }

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
    if (e.check==true){
        if (e.check==true){
        Database db;
        db.insertEmployee(e);
        e=db.selectEmployeeByEmail(e.email);
        e.showHeaderWithId();
        e.showDataWithId();
        e.showLineWhitId();
        }
    }
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
    if (e.check==true){
        e=selectEmployeeById(e.id);
        e.showHeaderWithId();
        e.showDataWithId();
        e.showLineWhitId();
        cout <<" ________________________"<<endl;
        cout <<"|    enter new details   |"<<endl;
        cout <<"|________________________|"<<endl;
        e.enter();
        if (e.check==true){
        db.updateEmployee(e);
        }
    }
}
void signEmployeeAsAdmin(){
     Employee e;
     e.enterId();
     if (e.check==true){
     SetAdmin(e.id);
     }
}
void deleteEmployee(){
    Database db;
    Employee e;
    showEmployee();
    e.enterId();
    if (e.check==true){
        if (e.check==true){
            e=selectEmployeeById(e.id);
            e.showHeaderWithId();
            e.showDataWithId();
            e.showLineWhitId();
            cout <<" __________________________"<<endl;
            cout <<"|  are you sure press Y/N  |"<<endl;
            cout <<"|__________________________|"<<endl;
            string  choice;
            cin>>choice ;
            if (choice=="y" || choice=="Y"){
            db.deleteEmployee(e.id);
            }
            int employeeId;
            for(employeeId : e.id){
                if(employeeId != 0){
                    db.unsignTaskFromEmployee(e.id);
                }
            }
        }
    }
}
long employeeLoginRecord(string id){
     list<Day> days;
     Database db;
     Loging l;
     Employee e;
     CustomTime c;
     long temp ;
     bool found=false;
     days =db.selectDayByEmployeeIdAndByDate(id);
     long current = CustomTime().getTimestampDate();
     for (d:days){
         string  currentDate =c.date2()+" "+ "00"+ ":" + "00" + ":" + "00";
         long currentTimeStampDate=c.getTimestampDate(currentDate);
         if (currentTimeStampDate == d.date){
             temp =current;
             found=true;
          }
     }
     if(found ==false){
         long current = CustomTime().getTimestampDate();
         db.insertStartEmployeeDay(id);
         temp =current;
    }
    return temp;
}
void employeeLogoutRecord(string id,long temp){
    Database db;
    CustomTime c;
    Day d;
    string  currentDate =c.date2()+" "+ "00"+ ":" + "00" + ":" + "00";
    long currentTimeStampDate=c.getTimestampDate(currentDate);
    list<Day> days;
    days=db.selectDayByEmployeeIdAndByDate(id);
    long curentTime = CustomTime().getTimestampDate();
    for(d :days){
        if(d.date==currentTimeStampDate){
            long sub=curentTime-temp;
            d.timeSpend=d.timeSpend+sub;
            d.endTime=curentTime;
            db.updeteEndEmployeeDay(d);
        }
    }
}
void convertTaskStatusIfStatusWasStarted(string id,long temp){
    Database db;
    Project p;
    CustomTime c;
    Day d;
    Task t;
    string  currentTime =c.fullDateTime2();
    long currentTimeStampDate=c.getTimestampDate(currentTime);
    list<Task> tasks;
    tasks=db.selectTasksByEmployeeId(id);
    for(t :tasks){
          if (t.status=="Started"){
            t.status="Paused";
            long sub=currentTimeStampDate-temp;
            long result=d.stringToLong(t.timeSpend)+sub;
            t.timeSpend=d.longToString(result);
            t.finish=d.longToString(currentTimeStampDate);
            db.updateTaskWhenLogOut(t);
            t=db.selectTask(t.id);
            p=db.selectProject(t.projectId);
            p.status="Started";
            long res=d.stringToLong(p.timeSpend)+sub;

            p.timeSpend=d.longToString(res);
            db.updateProject(p);
          }
    }

}
bool cancel(string input){
  bool cancl;
 if (input=="*"){
    cancl=false;
 }
 else{
    cancl=true;
 }
 return cancl;
}
bool cancelMenu(int &n){
  bool inputN=false;
   int  *p=&n;
 if (*p=='*'){
    inputN=false;
 }
 else{
    inputN=true;
 }
 return inputN;
}
void showSuggessByProjectId(string id){


    Sugges sg;
    Database db;
    list<Sugges> suggess;
    suggess=db.showSuggessByProjectId(id);
    sg.showHeader();
    for(sg :suggess){
          Employee e;
          Project p;
          Task t;
          e=db.selectEmployeeById(sg.e.id);
          p=db.selectProject(sg.p.id);
          t=db.selectTask(sg.t.id);
          sg.p.id=p.title;
          sg.e.id=e.name;
          sg.t.id=t.title;
          sg.showData();
  }

}
void showAllSuggess(){
  Sugges sg;
  Database db;
  list<Sugges> suggess;
  suggess=db.selectSuggestions();
  sg.showHeader();
  for(sg :suggess){
      Employee e;
      Task t;
      Project p;
      e=db.selectEmployeeById(sg.e.id);
      sg.e.id=e.name;
      p=db.selectProject(sg.p.id);
      sg.p.id=p.title;
      t=db.selectTask(sg.t.id);
      sg.t.id=t.title;
      sg.showData();
  }
}


  //end MOHAMAD.
