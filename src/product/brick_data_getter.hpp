// The header file of data_getter
#ifndef brick_data_getter_hpp
#define brick_data_getter_hpp
#include "brick.hpp"

/* ======== INFO TO THE OTHER DEVELOPERS ========
 * The virtual data_getter class is an example of
 * a "single-method interface" (SMI), where the interface's name is the method's name
 * with an "er" added to the end (within reason). In this case "get_brick_dataer" sounds
 * retarded, so instead it's "brick_data_getter".
 * The purpose of SMIs, is to promote the use of composition over inheritance,
 * where instead of inheriting data, you inherit the kind of behaviour you expect
 * from the class.
 * SMIs were popularised by the Go programming language, and have been shown to
 * work great in practice.
 */

/**
 * @brief data_getter defines an interface for classes that can get data from somewhere.
 * In practice this could be anywhere.
 */
struct brick_data_getter {
  /**
   * @return a brick if something's read, or a brick::empty_brick() if not.
   */
  virtual brick get_brick_data();
};

#endif
