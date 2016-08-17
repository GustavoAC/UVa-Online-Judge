#include <iostream>
#include <algorithm>
#include <vector>

struct Appointment {
    int hourStart;
    int minuteStart;
    int hourEnd;
    int minuteEnd;
};

bool sorter(const Appointment &a, const Appointment &b) {
    return (a.hourStart < b.hourStart) or
           (a.hourStart == b.hourStart and a.minuteStart < b.minuteStart);
}

int main(int argc, char* argv[]) {
    int numAppoints, dayCounter = 1;
    std::string wholeLine;
    std::vector<Appointment> appoints(100);

    while (std::cin >> numAppoints) {
        std::getline(std::cin, wholeLine); // Goes through last \n
        for (int i = 0; i < numAppoints; ++i) {
            std::getline(std::cin, wholeLine);

            appoints[i].hourStart = (wholeLine[0]-'0')*10 + wholeLine[1]-'0';
            appoints[i].minuteStart = (wholeLine[3]-'0')*10 + wholeLine[4]-'0';
            appoints[i].hourEnd = (wholeLine[6]-'0')*10 + wholeLine[7]-'0';
            appoints[i].minuteEnd = (wholeLine[9]-'0')*10 + wholeLine[10]-'0';
        }

        std::sort(appoints.begin(), appoints.begin() + numAppoints, sorter);

        int hourStartNap = 10;
        int minuteStartNap = 0;
        int spanNap = (appoints[0].hourStart - 10) * 60 + appoints[0].minuteStart;
        int currentNap;
        for (int i = 1; i < numAppoints; ++i) {
            currentNap = (appoints[i].hourStart - appoints[i-1].hourEnd) * 60
                         + appoints[i].minuteStart - appoints[i-1].minuteEnd;
            if (currentNap > spanNap) {
                spanNap = currentNap;
                hourStartNap = appoints[i-1].hourEnd;
                minuteStartNap = appoints[i-1].minuteEnd;
            }
        }

        currentNap = (18 - appoints[numAppoints-1].hourEnd) * 60
                     - appoints[numAppoints-1].minuteEnd;

        if (currentNap > spanNap) {
            spanNap = currentNap;
            hourStartNap = appoints[numAppoints-1].hourEnd;
            minuteStartNap = appoints[numAppoints-1].minuteEnd;
        }

        std::cout << "Day #" << dayCounter++
                  << ": the longest nap starts at " << hourStartNap << ":";
        std::cout.fill('0');
        std::cout.width(2);
        std::cout << minuteStartNap << " and will last for ";
        if (spanNap >= 60){
            std::cout << spanNap/60 << " hours and ";
        }
        std::cout << spanNap%60 << " minutes.\n";

    }

    return 0;
}
