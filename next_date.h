class Date {
	public:
		Date(unsigned int y, unsigned int m, unsigned int d);
		Date();

	  bool operator ==(const Date &rhs) const {
			return (rhs.year == year) && (rhs.mon == mon) && (rhs.day == day);
			}
		unsigned int year;
		unsigned int mon;
		unsigned int day;
	};

Date next_date(unsigned int y, unsigned int m, unsigned int d);

