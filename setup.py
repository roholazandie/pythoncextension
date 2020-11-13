from distutils.core import setup, Extension

def main():
    setup(name="calculate",
          version="1.0.0",
          description="Python interface for the fputs C library function",
          author="rz",
          author_email="rz@gmail.com",
          ext_modules=[Extension("calculate", ["calculatemodule.c"])])

if __name__ == "__main__":
    main()