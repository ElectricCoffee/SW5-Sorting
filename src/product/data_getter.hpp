// The header file of data_getter
#ifndef data_getter_hpp
#define data_getter_hpp

/* ======== INFO TO THE OTHER DEVELOPERS ========
 * The virtual data_getter class is an example of
 * a "single-method interface" (SMI), where the interface's name is the method's name
 * with an "er" added to the end (within reason). In this case "get_dataer" sounds
 * retarded, so instead it's "data_getter".
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
struct data_getter {
  virtual void get_data(const void*); // discuss type with group.
};

#endif
