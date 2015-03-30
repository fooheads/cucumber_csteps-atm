require 'cucumber_csteps'

CucumberCsteps.load_steps('atm', 'libatm.so', ["features/**/*.c"])
