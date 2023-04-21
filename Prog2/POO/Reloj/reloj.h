class reloj {
  int h, m, s;

public:
  reloj(int hr, int min, int seg);
  void setHora(int hr);
  void setMinuto(int min);
  void setSegundo(int seg);
  int getHora();
  int getMinuto();
  int getSegundo();
  void operator++();
};
