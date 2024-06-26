#include <iostream>
#include <string>
    std::string* TaskArrPend=new std::string[100];
    std::string* TaskArrComp=new std::string[100];
    int choice,sizep=0,sizec=0;
    void printArrPend() {
        for (int i = 0; i < sizep; i++) {
            std::cout << i + 1 <<" "<< TaskArrPend[i] << std::endl;
        }
    }
    void printArrComp() {
        for (int i = 0; i < sizec; i++) {
            std::cout << i + 1 <<" "<< TaskArrComp[i] << std::endl;
        }
    }
    int TaskCount;
    /*std::ostream& operator<<(std::ostream& out,const ArrayofPointers<std::string*>& Task)
    {
        out << Task; 
        return out;
    }*/
int main()
{
    while (true) {
    std::cout << "Pick an Operation:\n";
    std::cout << "1 to add a new task.\n2 to view tasks.\n3 to mark a task as completed.\n4 to remove a task.\n";
    std::cin >> choice;
        if (choice==1) {
            //  Add Task : Implement a function to add tasks to the list.
            std::string Task;
            int index = 0;
            std::cout << "Enter the tasks you want to add!\nEnter -1 to stop.\n";
            while (Task != "-1") {
                std::cin >> Task;
                TaskCount++;
                if (Task != "-1") {
                    TaskArrPend[index] = Task;
                    index++;
                    sizep++;
                }
            }
        }else if(choice==2){
              // View Tasks : Display the list of tasks with their status(completed or pending).
            std::cout << "You have " << sizep << " pending tasks:\n"; 
            printArrPend();
            std::cout << "You have " << sizec<<" completed"  << " tasks:\n";
            printArrComp();
        }else if(choice==3){
              //   Mark Task as Completed : Allow users to mark tasks as completed.
            printArrPend();
            std::cout << "\nPick the number of the task to mark as completed.\nEnter -1 to stop.\n";
            
            int index;
            std::cin >> index;
            while (index != -1) {
                TaskArrComp[sizec] = TaskArrPend[index-1];
                sizec++;
                for (int i = index - 1; i < sizep; i++) {
                    TaskArrPend[i] = TaskArrPend[i + 1];
                }
                sizep--;
                std::cout << "Pick another number!\n";
                printArrPend();
                std::cin >> index;
            }
        }else if (choice==4){
              //    Remove Task : Provide an option to remove tasks from the list.
            std::cout << "Enter 1 to remove from pending tasks, or 2 to remove from completed tasks.\n";
            int choice;
            std::cin >> choice;
            std::cout << "Pick the number of the task you want to remove!\nEnter -1 to stop.\n";
            if (choice == 1) {
                int index;
                std::cin >> index;
                while (index != -1) {
                    for (int i = index - 1; i < sizep; i++) {
                        TaskArrPend[i] = TaskArrPend[i + 1];
                    }
                    sizep--;
                    std::cout << "Pick another number!\n";
                    printArrPend();
                    std::cin >> index;
                }
            }
            else if (choice == 2) {
                int index;
                std::cin >> index;
                while (index != -1) {
                    for (int i = index - 1; i < sizec; i++) {
                        TaskArrComp[i] = TaskArrComp[i + 1];
                    }
                    sizec--;
                    std::cout << "Pick another number!\n";
                    printArrComp();
                    std::cin >> index;
                }
            }
        }else {
            std::cout << "You picked an invalid number.\nEnter any number.\n";
            std::cin >> choice;
        }
    }
      // Task Input : Allow users to input tasks they want to add to the list.
}
