#include <map>

class Registry {
    public:
        void set(std::string what, std::string with) {
            Container [what] = with;
        }

        void get(std::string what) {
            return Container [what];
        }

    private:
        std::map < std::string, std::string > Container;
};
