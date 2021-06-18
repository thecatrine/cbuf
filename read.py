import cffi

ffi = cffi.FFI()

with open('schema.h') as f:
    buf = f.read()

ffi.cdef(buf)

with open('test.obj', 'rb') as f:
    c = ffi.from_buffer(f.read())
    a = ffi.cast("struct test *", c)

test = ffi.string(a.test)
print(f"test {test}, foo {a.foo}, bar {a.bar}")    

    
