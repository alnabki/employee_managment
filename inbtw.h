#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED
#include <timoff.h>
#include <employee.h>


// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void createDatabase();

//Task ONLY
void inbtwShowTask(std::string taskId);
void inbtwInsertTask(std::string projectId);
void inbtwDeleteTask(std::string id);
void inbtwUpdateTask();
void inbtwShowAllTasks();
void inbtwSignEmployeeToTask(std::string taskId, std::string employeeId);
void inbtwStartTask(std::string taskId,std::string employeeId);
void inbtwPauseTask(std::string id);
void inbtwEndTask(std::string id);
//Task end

//Project ONLY
void inbtwShowAllProjects();
void inbtwInsertProject();
void inbtwDeleteProject(std::string id);
void inbtwUpdateProject();
long stringToLong(std::string str);
long longToString(std::string str);
//project end
// end gab

//MOHAMAD
void showDays( long date1,long date2,std::string id);
void showTaskForEmployee(std::string employeeId);
void showTimesOffWithId(std::string id);
void showTimeOff(std::string id);

void showEmployee();
void insertTimeOff(TimeOff timeOf);
void updateTimeOff(TimeOff timeOf);
void deleteTimeOff(std::string id);
TimeOff selectTimeOff(std::string id);
void insertEmployee();
void updateEmployee();
void deleteEmployee();
void signEmployeeAsAdmin();
long employeeLoginRecord(std:: string id);
void employeeLogoutRecord(std::string id,long temp);
bool cancel(string input);
bool cancelMenu(int &n);
void showProjectsWithTasks(string id);
void showProjectsWithTasksForAdmin();
void showAllTasksForProject(string id);
void convertTaskStatusIfStatusWasStarted(string id,long temp);
void showSuggessByProjectId(string id);
void showAllSuggess();
void signEmployeeToTask();
void inbtwStartTask(string taskId,string employeeId);
void inbtwPauseTask(string taskId);
void inbtwEndTask(string taskId);



void inbtwInsertEmployee();
void inbtwUpdateEmployee();
void inbtwDeleteEmployee();
void inbtwShowEmployees();
void inbtwSignEmployeeAsAdmin();
void inbtwShowWorkDetails(string id);
void inbtwShowTaskForEmployee(string id);
void inbtwShowTimeOff(string id);

/*
Employee selectEmployeeByEmail(std::string email);
Employee selectEmployeeById(std::string id);
*/

#endif // INBTW_H_INCLUDED
