#ifndef RUNNABLE_H_
#define RUNNABLE_H_

#include <thread>

/**
 * Base class for event generators/processors. Infinite loop is run in a separate thread where a callback is called periodically. Override the callback in derived classed.
 *
 */
class Runnable
{
public:

  enum tState
  {
    IDLE = 0, RUNNING, STOPPING, STOPPED
  };

  /// Transition to RUNNING state; returns new state
  tState
  start ();

  /// Transition to STOPPED state; return new state
  tState
  stop ();

  /// Returns curret state
  tState
  getState () const;

  /// joins this thread
//  void join();

  Runnable();

  virtual
  ~Runnable ();

protected:

  /// Will be called from run periodically; override to be useful; return time to sleep in ms
  virtual int
  onIdle () = 0;

private:

  /// Loop, called onIdle periodically
  void
  run ();

  tState _State;
  std::thread _Thread;
};

#endif /* RUNNABLE_H_ */
