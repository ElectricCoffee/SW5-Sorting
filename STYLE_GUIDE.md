# C++ Style Guide!!

## Naming Convention

All lower-case except for constants, example:

```cpp
const int DAYS_IN_WEEK = 7;
int new_days = convert_days_to_week(days, DAYS_IN_WEEK);
```

In classes, `public`, `protected`, and `private` are on the same indentation level as the class itself:

```cpp
// GOOD
class foo {
public:
  int get_data();
private:
  int mediate_data();
};

// BAD
class foo {
  public:
    int get_data();
  private:
    int mediate_data();
};
```

Same goes for `case`s in `switch`:

```cpp
switch(foo) {
case bar:
  do_stuff();
  break;
default:
  break_stuff();
}
```

## Spacing and Indentation

Indent by 2 spaces per level only, no more, no less.

```cpp
if (foo) {
  stuff(); // GOOD
    stuff(); // BAD
        stuff(); // WORSE
}
```

Space between the keyword and opening parenthesis `(` in `if`, `switch`, `while`, and `foo`.

```cpp
// GOOD
if (foo);
switch (foo) {}
while (foo);
for (foo; bar; baz);

// BAD
if(foo);
switch(foo) {}
while(foo);
for(foo; bar; baz);
```

Space between something and the opening brace `{`

```cpp
// GOOD
class foo {};
if (foo) {}
void foo() {}

// BAD
class foo{};
if (foo){}
void foo(){}
```

## Curly Brace Placement

There's a wide variety of curly brace placements in use. Here's a few of them:

```cpp
// K&R Style
void foo() {
  do_stuff();
  do_more_stuff();
}

// Allman Style
void foo()
{
  do_stuff();
  do_more_stuff();
}

// Whitesmiths Style
void foo()
  {
  do_stuff();
  do_more_stuff();
  }

// Hortsmann Style
void foo() 
{ do_stuff();
  do_more_stuff();
}

// Haskell Style
void foo()
  { do_stuff()
  ; do_more_stuff()
  ; }
```

We'll be using the first one: K&R Style.

Additionally, writing if-else chains come in two variants:

```cpp
// OTBS (One True Brace Style)
if (foo) {
  do_stuff();
} else {
  do_other_stuff();
}

// Stoustrup Style
if (foo) {
  do_stuff();
}
else {
  do_other_stuff();
}
```

Either is fine, but OTBS is preferred for brevity.

## To Brace or not to Brace

For the sake of sanity, always add braces to your statements, even if they only contain a single line of code.
This allows you to easier extend your statements (`if`, `switch`, `while`, and `foo`) without then having to add braces.
