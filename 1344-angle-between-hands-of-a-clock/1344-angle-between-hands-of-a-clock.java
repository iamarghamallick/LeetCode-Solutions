class Solution {
    public double angleClock(int hour, int minutes) {
        double posH = (minutes * (double)5 / 60) + ((hour * 5) % 60);
        double posDiff = Math.abs(posH - minutes);
        double angleDiff = posDiff * 360 / 60;
        return angleDiff > 180 ? 360 - angleDiff : angleDiff;
    }
}