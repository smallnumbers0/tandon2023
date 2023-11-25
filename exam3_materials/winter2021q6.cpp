//winter 2021
bool busTooClose(string busLine) {
    vector<double> busses = getBusLineInfo(busLine);//This should return a vector of numbers
    sort(getBusLineInfo(busses.begin(), busses.end()));

    for(int i = 0; i < busses.size(); i++) {
        if(busses[i+1] - busses[i] < 1 ) {
            return true;
        }
    }
    return false;
}

