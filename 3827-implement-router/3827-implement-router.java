class Router {
    static class Packet {
        int source;
        int destination;
        int timestamp;

        Packet(int source, int destination, int timestamp) {
            this.source = source;
            this.destination = destination;
            this.timestamp = timestamp;
        }
    }

    int memoryLimit;
    Queue<String> q;
    HashMap<String, Packet> map;
    HashMap<Integer, ArrayList<Integer> > destTime;

    public Router(int memoryLimit) {
        this.memoryLimit = memoryLimit;
        q =  new LinkedList<>();
        map = new HashMap<>();
        destTime = new HashMap<>();
    }
    
    public boolean addPacket(int source, int destination, int timestamp) {
        Packet packet = new Packet(source, destination, timestamp);
        String packetKey = "" + source + "_" + destination + "_" + timestamp;
        if(map.containsKey(packetKey)) return false;
        if(q.size() >= memoryLimit) forwardPacket();
        q.offer(packetKey);
        map.put(packetKey, packet);

        ArrayList<Integer> destTimeArr = destTime.getOrDefault(destination, new ArrayList<>());
        destTimeArr.add(timestamp);
        destTime.put(destination, destTimeArr);

        return true;
    }
    
    public int[] forwardPacket() {
        if(!q.isEmpty()) {
            String packetKey = q.poll();
            Packet packet = map.get(packetKey);
            map.remove(packetKey);

            ArrayList<Integer> destTimeArr = destTime.get(packet.destination);
            destTimeArr.remove(0);
            destTime.put(packet.destination, destTimeArr);

            int[] ans = { packet.source, packet.destination, packet.timestamp };
            return ans;
        }
        return new int[0];
    }
    
    public int getCount(int destination, int startTime, int endTime) {
        ArrayList<Integer> destTimeArr = destTime.getOrDefault(destination, new ArrayList<>());
        int lb = lowerbound(destTimeArr, startTime);
        int ub = upperbound(destTimeArr, endTime);
        return ub - lb + 1;
    }

    private int lowerbound(ArrayList<Integer> arr, int x) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr.get(mid) < x)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo; // first index where arr[i] >= x
    }

    private int upperbound(ArrayList<Integer> arr, int x) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr.get(mid) <= x)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo - 1; // last index where arr[i] <= x
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * boolean param_1 = obj.addPacket(source,destination,timestamp);
 * int[] param_2 = obj.forwardPacket();
 * int param_3 = obj.getCount(destination,startTime,endTime);
 */