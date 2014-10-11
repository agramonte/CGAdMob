# -*- coding: utf-8 -*-
#
# (C) 2001-2012 Marmalade. All Rights Reserved.
#
# This document is protected by copyright, and contains information
# proprietary to Marmalade.
#
# This file consists of source code released by Marmalade under
# the terms of the accompanying End User License Agreement (EULA).
# Please do not use this program/source code before you have read the
# EULA and have agreed to be bound by its terms.
#
import deploy_config

config = deploy_config.config
cmdline = deploy_config.cmdline
mkb = deploy_config.mkb
mkf = deploy_config.mkf

assets = deploy_config.assets

class HubConfig(deploy_config.DefaultConfig):
    iphone_application_type = "universal"
    iphone_appid = ur"com.cabagomez.com.CGAdmobExample"
    iphone_minimum_ios_version = ur"5.0"
    assets = assets["Default"]
    config = [ur"/Users/adriangomez/OneDrive/Development/CGAdmobExample/data/app.icf"]
    name = ur"CGAdmobExample"
    caption = ur"CGAdmobExample"
    provider = ur"cabagomez.com"
    copyright = ur"(C) cabagomez.com"
    version = [0, 0, 1]
    iphone_region = ur"English"
    pass

default = HubConfig()
