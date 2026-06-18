// 1344. Angle Between Hands of a Clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minDeg = minutes * 6; 
        if(hour == 12) hour = 0 ; 
        double hourDeg = (hour * 30) + (minutes * 0.5);

        return min(abs(hourDeg - minDeg), 360 - abs(hourDeg - minDeg));
    }
};