# Reading directly from the std input may be dangerous

As shown in the example, inputing "passwd\<tab>true" in the passwd field will cause unexpected behavior. We can't control what users input, while we can control ourselves not reading directly from the `cin`, that's why we should use `getline` instead.

# Space won't break the `cin >>`, but tab will

If "passwd\<tab>true" is changed to "passwd\<space>true", the variable `passwd` won't be "passwd", it will be "passwd\<space>true" instead.

# The manipulator `boolaphal` is used in this example

and in both `cin` and `cout` cases.