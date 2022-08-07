# Electric

A hackable, native scripting/compiled language.

How it works:

```rust
a: int = 10;
b: int = 10;

a + b;

fn add(one: int, two: int): int {
    one + two
}

options: dyn object = {

}

// type inference allowed
// imports
use sys
use proc

if sys.os.name != "windows" {
    print("You can not run this script")
    proc.end(0) ? halt!;
}
```

Easeful error catching with `Result` and `Err` classes:

```rust
import std::net::http_util;

result = await fetch('url', { method: "GET" }).json() ? { error: "Failed to get request" };
if result.error {
    print(result.error)
}

// or
panics = proc.send(SIG_TERM) ? print("Failure") </ print("Success");
// or
panics = match proc.send {
    Result(_) => print("success"),
    Error(_) => print("Failure")
}
```

Inline match statements

```rust
some_result = @enumOfNumbers ? 10 => print("Number is 10!"), 30 => print("Number is 30!"); _ => print("Unknown number");
```

Customising your own scopes with the token parser

```rust
declare LableName {
    tokens = @tokens;
    script: Script;

    parseableFn = ["VAR", "WITH"];
    tempStack: void[] = [];

    for token in tokens {
        @token.label() ?
            "VAR" => script.addVar(tokens.next(), CONSTANT),
            "WITH" => script.pushStack(resolveFn(tokens.next(), script.lastVar ?? "")
    }
    script.exec(this) 
}

//usage
LableName {
    VAR "hi"
    WITH println
}
```

    
