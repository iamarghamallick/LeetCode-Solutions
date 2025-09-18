class TaskManager {
    static class Task implements Comparable<Task> {
        int userId;
        int taskId;
        int priority;

        Task(int u, int t, int p) {
            this.userId = u;
            this.taskId = t;
            this.priority = p;
        }

        public int compareTo(Task other) {
            if (this.priority != other.priority)
                return other.priority - this.priority; // higher priority first
            return other.taskId - this.taskId; // then, higher taskId first
        }
    }

    TreeSet<Task> taskSet = new TreeSet<>();
    HashMap<Integer, Task> taskMap = new HashMap<>();

    public TaskManager(List<List<Integer>> tasks) {
        for (List<Integer> task : tasks) {
            int userId = task.get(0);
            int taskId = task.get(1);
            int priority = task.get(2);

            Task newTask = new Task(userId, taskId, priority);
            taskSet.add(newTask);
            taskMap.put(taskId, newTask);
        }
    }

    public void add(int userId, int taskId, int priority) {
        Task newTask = new Task(userId, taskId, priority);
        taskSet.add(newTask);
        taskMap.put(taskId, newTask);
    }

    public void edit(int taskId, int newPriority) {
        Task existingTask = taskMap.get(taskId);
        taskSet.remove(existingTask);
        Task newTask = new Task(existingTask.userId, taskId, newPriority);
        taskSet.add(newTask);
        taskMap.put(taskId, newTask);
    }

    public void rmv(int taskId) {
        Task existingTask = taskMap.remove(taskId);
        taskSet.remove(existingTask);
    }

    public int execTop() {
        if (taskSet.size() > 0) {
            Task topTask = taskSet.first();
            taskSet.remove(topTask);
            taskMap.remove(topTask);
            return topTask.userId;
        }

        return -1;
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */