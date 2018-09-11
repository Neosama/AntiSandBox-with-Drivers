
BOOL AntiSandbox_Drivers()
{
	LPVOID drivers[1024];
	DWORD cbNeeded;
	int cDrivers, i;
	int score = 0;

	if (K32EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded) && cbNeeded < sizeof(drivers))
	{
		TCHAR szDriver[1024];

		cDrivers = cbNeeded / sizeof(drivers[0]);

		for (i = 0; i < cDrivers; i++)
		{
			if (K32GetDeviceDriverBaseNameA(drivers[i], szDriver, sizeof(szDriver) / sizeof(szDriver[0])))
			{
				if (_tcscmp(szDriver, _T("dxgkrnl.sys")) == 0)
				{
					score++;
				}

				if (_tcscmp(szDriver, _T("nwifi.sys")) == 0)
				{
					score++;
				}

				if (_tcscmp(szDriver, _T("ksthunk.sys")) == 0)
				{
					score++;
				}

				if (_tcscmp(szDriver, _T("vwififlt.sys")) == 0)
				{
					score++;
				}
			}
		}
	}

	if (score >= 2)
		return TRUE;

	return FALSE;
}
