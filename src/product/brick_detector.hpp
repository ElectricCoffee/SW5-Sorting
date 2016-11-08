// The header file of brick_detector
#ifndef brick_detector_hpp
#define brick_detector_hpp

/* ======== INFO TO THE OTHER DEVELOPERS ========
 * The virtual brick_detector class is an example of
 * a "single-method interface" (SMI), where the interface's name is the method's name
 * with an "er" added to the end (within reason). In this case "detect_bricker" sounds
 * retarded, so instead it's "brick_detector".
 * The purpose of SMIs, is to promote the use of composition over inheritance,
 * where instead of inheriting data, you inherit the kind of behaviour you expect
 * from the class.
 * SMIs were popularised by the Go programming language, and have been shown to
 * work great in practice.
 */

struct brick_detecor {
  virtual bool detect_brick();
};

#endif
