# Options-Pricing-Tool
Options pricing tool written in C++. Supports pricing the following options with a multithreaded Monte Carlo simulation utilising geometric Brownian motion.

### European Style
 - Vanilla call
 - Call with squared payoff
 - Vanilla put
 - Put with squared payoff
 - Chooser option
 - Lookback put
 - Lookback call
 
 ### Asian Style
  - Fixed Strike Arithmetic put
  - Fixed Strike Arithmetic call
  - Fixed Strike Arithmetic lookback
  - Fixed Strike Geometric put
  - Fixed Strike Geometric call
  - Fixed Strike Geometric lookback

*Multithreading support by default takes the max number of cores provided by the CPU, this can be overwritten with the thread_override parameter.

TODO: American options, pricing with the binomial method and pricing options more efficiently with monte carlo and the binomial method by exploiting GPU programming.
