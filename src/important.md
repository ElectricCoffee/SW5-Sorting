# C++ Crash Course!

So, here's the deal.

I know you gringos are used to C#, so here's how the basics work in C++:

## How to Use Headers

The header file, `*.hpp`/`*.h`/`*.hh` (we'll use `*.hpp` because it mirrors `*.cpp`) is where the basic class structure goes, NOT its implementation!

Meaning you don't write method bodies in the header file (although you can, but it defeats the purpose).

Here's an example class:

```cpp
class person {
public:
  string name;
  int age = 0; // default values are ok
  
  void say_hello();
  person(string);
}; // don't forget the ;
```
And here's what you write in the `*.cpp` file:

```cpp
void person::say_hello() {
  printf("Hello there!\n");
}

person::person(string new_name) {
  name = new_name;
}
```

## Scoping in C++

`::` is the **static scope operator**, it's used for traversing static scopes, such as namespaces and static classes.
`System.Collection.Generic.List` in C#
would be written as `System::Collection::Generic::List` in C++.

`.` is the **direct component selector** as you know it from C, meaning value instances of classes are typically accessed with it:

```cpp
person p("Niko");
p.say_hello();
```

`->` is the **indirect component selector**, also as you know it from C, meaning reference types are typically accessed with it:

```cpp
person *p = new person("Niko");
p->say_hello();
```

C# makes no distinction between either of these three, and just uses `.` for all the cases, but C++ does not, so be careful what you write.

**Note:** I say _typically_ because there are cases where the indirect component selector are used with value instances.

## Value vs Reference Instances
So as you saw in the section above, C++ lets you create objects in two different ways: as _values_, and as _references_.

The main difference is that value instances get collected at the end of a scope, while reference instances stick around afterwards.

```cpp
void example() {
  person p1("Niko"); // value instance
  person *p2 = new person("Anders"); // reference instance
}
```

In the above code, `p1` gets de-allocated when the `example` function's body ends, but `p2`'s data sticks around, even though the variable can't be accessed, creating a memory leak.

### Different Constructors?
As you probably noticed, when you create a value instance, you _don't_ use the `new` keyword, you simply add the constructor parameters to the variable name itself. 

Creating a reference instance is just like how it is in C#, except you need to declare the type as a pointer (because it's a reference, duh).

### Empty Constructors?

In C++ making a new instance of a class without any input parameters works like this:

```cpp
person p1;
person *p2 = new person;
```

## Freeing Memory
Okay so, if you can create reference instances, surely you can free the memory again, right?

Alright, so remember how in C you had `malloc` for allocation and `free` for deallocation?

C++ uses `new` for allocation, and `delete` to deallocate.

```cpp
person *p = new person("Niko");
// do stuff with p
delete p;
```

Please note that you don't use `*` or `&` when deleting the pointer.

## Class Destructors
In addition to **con**structors, C++ also supports **de**structors, which contain code that will execute when an instance is being deleted.

Destructors are written just like constructors, except they're prefixed with a `~`.

```cpp
class example {
public:
  point(); // constructor
  ~point(); // destructor
};

example::example() {
  printf("Example is created\n");
}

example::~example() {
  printf("Example is removed\n");
}
```

Now when you use the object as normal

```cpp
example *e = new example;
printf("Hello!\n");
delete e;
```

The output will be as follows
```cpp
Example is created
Hello!
Example is removed
```

## Multiple Inheritance
C++ supports multiple inheritance right out of the box, and the headaches associated with it is the reason we have interfaces in C# and Java.

That said, multiple inheritance makes a lot of sense, and if used correctly will work in your favour (after all, a child has genes from **two** parents, not one, right?).

The age of C++ and its use of multiple inheritance also means there aren't any interfaces in the language.

### Wait, no Interfaces?

That's right! No interfaces!

What you do instead, is write classes with virtual methods (i.e. abstract classes)

```cpp
class foo {
public:
  virtual void override_me();
}

class bar : public foo {
public:
  virtual void override_me();
}

void bar::override_me() {
  // do stuff
}
```

### Wait... class bar : public foo?
Yes! One of C++'s cooler features!

When you inherit in C++ you get to decide _how_ the access specifiers are carried over.

So when you write `class bar : public foo`, the class is inherited exactly how you'd expect it to be from C#, all that's `public` remains `public`, all that's `protected` remains `protected`, and all that's `private` remains `private`.

If you write `class bar : protected foo`, all the `public` members in `foo` are now `protected` in `bar`.

And if you write `class bar : private foo`, all `public` and `protected` members become `private` in `bar`.

This essentially lets you control the access level of things in the sub-classes.

## Include Guards
You probably noticed some weird code in some of the files
```cpp
#ifndef foo_hpp
#define foo_hpp
// code goes here
#endif
```
This, is an include guard.

Include guards are basically a little piece of hard-coded mechanism for avoiding multiple inclusions of a file.

Thing is, when you include a library in C/C++, often times the file included file is merely pasted into wherever it was included. Yes _pasted_. 

`#` macros are compile-time text-replacement tools, which means they don't know what context means. As such, the include guard works a bit like so:

* If the constant (in this case) `foo_hpp` isn't defined
* Then Define the constant `foo_hpp` and paste all the code before `#endif`
* Else _copy nothing_ at all

The fact that it doesn't copy anything essentially means there's no way of having the code being included in the compilation process more than once.
