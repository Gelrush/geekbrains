#include <iostream>
#include <string>

using namespace std;

struct Advertising
{
    int countAds;
    float press;
    float earn;
};

void printcalcAdvertising(Advertising site)
{
    cout << "\nAds shown: " << site.countAds;
    cout << "\nClicked on the ad: " << site.press;
    cout << "\nAverage earnings for ad: " << site.earn;
    cout << "\nAverage earnings per day: " << site.countAds * site.press / 100 * site.earn;
}

int main()
{
    Advertising siteA { 150, 60, 2 };
    printcalcAdvertising(siteA);
    printcalcAdvertising({ 250, 30, 1.5});
    
    return 0;
}