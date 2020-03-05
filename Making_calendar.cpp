#include <vector>
#include <iostream>
#include <fstream>
#include <string>

constexpr int N {1};

struct Event {
  std::string event_summary;
  std::string DTSTART;//DTSTART:20200201T060000
  std::string DTEND;//DTEND:20200201T180000
};
int main(int argc, char** argv) {
  std::string filename = "calendar.ics";
  std::vector<Event> event_vec(N);
  for (auto i = 0;i < N;++i) {
    event_vec[i].event_summary = "Summary";
  }
  event_vec[0].DTSTART = "20200201T060000";
  event_vec[0].DTEND   = "20200201T180000";

  std::ofstream ofs;
  ofs.open(filename, std::ios::out);
  std::string begin_string {"BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:\nCALSCALE:GREGORIAN\nX-WR-CALNAME;VALUE=TEXT:ical_test_csv\n"};
  ofs << begin_string;
  for (auto i = 0;i < N;++i) {
    ofs << "BEGIN:VEVENT\n";
    ofs << "SUMMARY:";
    ofs << event_vec[i].event_summary << '\n';
    ofs << "DESCRIPTION:\n";
    ofs << "DTSTAMP:\n";
    ofs << "DTSTART:" << event_vec[i].DTSTART << '\n';
    ofs << "DTEND:"   << event_vec[i].DTEND   << '\n';
    ofs << "LOCATION:\n";
    ofs << "UID:\n";
    ofs << "END:VEVENT\n";
  }
  std::string end_string{"END:VCALENDAR"};
  ofs << end_string;
}
