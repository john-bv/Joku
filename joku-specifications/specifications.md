<!--
@mock "NVScript"
@author "John"
@revision "1.0"
-->

<h1 id="introduction">1. Introduction</h1>

This is the official reference for the Joku programming language.

Joku is a multipurpose language designed for both systems and embeded programming. Joku is a type elegant and memory safe programming language.

The syntax of Joku is designed to be purposeful and efficient to write in; similar to that of [Rust](https://www.rust-lang.org), [C++](https://docs.microsoft.com/en-us/cpp/cpp/cpp-language-reference?view=msvc-170) and [Typescript](https://typescriptlang.org).

To view the chapters of the specification [click here](#index)

<h1 id="syntax">2. Syntax Overview</h1>

The Joku lexer is composed of the following parts:

1. [Keywords](#syntax-keywords)

2. [Identifiers](#syntax-identifiers)

3. [Literals](#syntax-literals)

4. [Operators]

5. [Punctuator]

6. [End of File]

7. [Comment Singleton]

8. [Comment]

9. [Token]

Each of these components is relevant to a file serving as Source Code. This code should be encoded in `UTF-8`.

<h3 id="syntax-keywords">2.1 Keywords</h3>

A keyword is a word that is reserved by the compiler that serves a specific function or purpose. For implementations regarding these keywords refer to ~~[this chapter](todo)~~.

Joku reserves the following keywords:

```diff
Abstract            Asm                 Await
Async               As                  Become
Break               Case                Catch
Class               Continue            Data
Delete              Do                  Else
Enum                Export              Extends
Extern              False               Final
For                 From                Fn
If                  Import              In
Is                  Let                 Loop
Match               Mod                 Of
Priv                Pub                 Prot
Return              Self                Static
Super               True                Trait
Try                 Type                Throw
Type                Typeof              Var
Where               While               Yeild
```

<h3 id="syntax-identifiers">
2.2 Identifiers
</h3>

An Identifier is a name for an entity such as a typename. Identifiers are composed of a sequence of one or more letters and digits.

Some Examples of identifers could be:

- `foo`

- `Bar`

- `_foobar`

- `$`

#### Identifier Rules

1. An identifier **must** start with a letter or non-digit char that is not a language component.

2. An identifier may not be the name of a reserved word, such as a keyword.

3. May not contain a zero-width character.

4. Must be present infront of an expression or declaration. 

<h3 id="syntax-literals">
  2.3 Literals
</h3>

In Joku a literal is a type of  `expression`. A literal is composed of one token rather than many, making it directly represent a value.

Each literal is a constant expression, meaning that it is evaluted during compilation. A literal is phyiscally one of the following types:



```rust
'j'   // char
"oku" // string
true  // boolean
1     // number
```

It is important to note that numbers or chars are not validated at tokenization.

For example, the following code would pass tokenization but not parsing.

```rust
x = 0.3EF___+93
```

---

<h1 id="source-files">3. Modules and Source Files</h1>

---

## Index

1. [Introduction](#introduction)

2. [Syntax](#syntax)
   
   1. [Keywords](#syntax-keywords)
   
   2. [Identifiers](#syntax-identifiers)
   
   3. [Literals]
   
   4. [Operators]
   
   5. [Punctuator]
   
   6. [End of File]
   
   7. [Comment Singleton]
   
   8. [Comment]
   
   9. [Token]