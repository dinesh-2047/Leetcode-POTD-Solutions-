// 3408. Design Task Manager


class TaskManager {
public:

unordered_map<int, int>task_user; 
unordered_map<int , int>task_priority; 
set<pair<int , pair<int ,  int>>>priority_task_user;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks){
            int user_id = task[0];
            int task_id = task[1];
            int priority = task[2];

            task_user[task_id] = user_id; 
            task_priority[task_id] = priority; 
            priority_task_user.insert({-priority, {-task_id, user_id}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
           task_user[taskId] = userId; 
            task_priority[taskId] = priority; 
            priority_task_user.insert({-priority, {-taskId, userId}});
    }
    
    void edit(int taskId, int newPriority) {
        int user_id = task_user[taskId];
        int prev_priority = task_priority[taskId];
          task_priority[taskId] = newPriority; 
        priority_task_user.erase({-prev_priority , {-taskId, user_id}});
        priority_task_user.insert({-newPriority, {-taskId, user_id}});
    }
    
    void rmv(int taskId) {
         int user_id = task_user[taskId];
         int priority = task_priority[taskId];
         task_user.erase(taskId);
         task_priority.erase(taskId);
         priority_task_user.erase({-priority, {-taskId, user_id}});
    }
    
    int execTop() {
        if(priority_task_user.empty()) return -1; 
        else {
           int user_id =   priority_task_user.begin()->second.second; 
           priority_task_user.erase(priority_task_user.begin());
           return user_id;
        }
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */