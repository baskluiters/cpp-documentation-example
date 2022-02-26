# Run with: source activate.sh

if [ ! -d .my_super_project ]; then
    python3 -m venv .my_super_project
fi

if [ -z ${VIRTUAL_ENV} ]; then 
    source ./.my_super_project/bin/activate
fi
if [ -z ${VIRTUAL_ENV} ]; then 
    exit 1
fi

# DRAWIO is to be set to the location of the executable
if [ -f /Applications/draw.io.app/Contents/MacOS/draw.io ]; then
    export DRAWIO="/Applications/draw.io.app/Contents/MacOS/draw.io"
fi

# checking required packages
pip install -q --upgrade pip
pip install -q -r ./requirements.txt
pip install -q -r ./docs/requirements.txt

# Add java to the path
if [[ ":$PATH:" != *"/usr/local/opt/openjdk/bin/:"* ]]; then
  export PATH="/usr/local/opt/openjdk/bin/:$PATH"
fi

cmake .
