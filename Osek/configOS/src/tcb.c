/* file: tcb.c, automatically generated by gentricAS.exe, Version: 5.05 */
/* configuration read from: C:\OS\OS2.0\OS_CONF.OIL */
/* generation at  : Thu Apr 21 09:39:04 2011 */
/* License CBD1000119 for BEIQI FOTON MOTOR CO.,LTD., beta license (valid from 2010-08-18 until 2011-08-31) */
/* Implementation: TriCore_1767 */
/* Version of general code: 5.15a */

#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
#define osdVrmGenMajRelNum 5
#define osdVrmGenMinRelNum 5
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

/* Start of invariant part */
#if defined USE_QUOTE_INCLUDES
 #include "Os.h"
#else
 #include <Os.h>
#endif
#if defined USE_QUOTE_INCLUDES
 #include "osekext.h"
#else
 #include <osekext.h>
#endif

   /* structure for standard counter (derived from system clock) */
   osqROM0 osqROM1 const osqROM2 AlarmBaseType osqROM3 oskAlarmDefinitions=
   {
      (TickType) OSMAXALLOWEDVALUE,
      OSTICKSPERBASE,
      OSMINCYCLE
   };

   osqTcbRAM1 osqTcbRAM2 TickType osqTcbRAM3 osAlarmTime[osdNumberOfAlarms];
   #ifndef osdUseGeneratedFastAlarm
      osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osAlarmActivated[osdNumberOfAlarms];
      osqTcbRAM1 osqTcbRAM2 osHeapType osqTcbRAM3 osAlarmHeap[osdNumberOfAlarms+1];    /* Minimum Heap */
   #endif

   #if (osdNumberOfVarAlarms > 0)
   osqTcbRAM1 osqTcbRAM2 TickType osqTcbRAM3 osAlarmCycleTime[osdNumberOfVarAlarms];
   #endif

#if (osdNumberOfScheduleTables > 0)
   osqRAM1 osqRAM2 osSTIndexType osqRAM3 osSTCurrentIndex[osdNumberOfScheduleTables];
   osqRAM1 osqRAM2 osSTOffsetType osqRAM3 osSTCounter[osdNumberOfScheduleTables];
   osqRAM1 osqRAM2 ScheduleTableStatusType osqRAM3 osSTState[osdNumberOfScheduleTables];
   osqRAM1 osqRAM2 ScheduleTableType osqRAM3 osSTNextTable[osdNumberOfScheduleTables];
#else
   osqRAM1 osqRAM2 osSTIndexType osqRAM3 osSTCurrentIndex[1];
   osqRAM1 osqRAM2 osSTOffsetType osqRAM3 osSTCounter[1];
   osqRAM1 osqRAM2 ScheduleTableStatusType osqRAM3 osSTState[1];
   osqRAM1 osqRAM2 ScheduleTableType osqRAM3 osSTNextTable[1];
#endif
#if (CC==BCC2) || (CC==ECC2)
   #if (osdNumberOfPriorities > 0)
      osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskHead[osdNumberOfPriorities];
      osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskTail[osdNumberOfPriorities];
   #else
      osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskHead[1];
      osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskTail[1];
   #endif
#else
   #if (osdNumberOfPriorities > 0)
      osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQReadyTask[osdNumberOfPriorities];
   #else
      osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQReadyTask[1];
   #endif
#endif

#if ((CC == BCC2) || (CC == ECC2))
   #if (osdNumberOfAllTasks > 0)
      osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[osdNumberOfAllTasks];
   #else
      osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[1];
   #endif
#endif

#if (osdRTSize > 1)
   osqRAM1 osqRAM2 osPrioFlagType osqRAM3 osQReadyPrios[osdRTSize];
#else
   osqRAM1 osqRAM2 osPrioFlagType osqRAM3 osQReadyPrios;
#endif

#if (osdNumberOfAllTasks > 0)
   osStackPtrType osqTcbRAM1 osqTcbRAM2 osqTcbRAM3 osTcbPCXI[osdNumberOfAllTasks];
#else
   osStackPtrType osqTcbRAM1 osqTcbRAM2 osqTcbRAM3 osTcbPCXI[1];
#endif
#if (osdNumberOfAllTasks > 0)
   osqTcbRAM1 osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[osdNumberOfAllTasks];
   #if osdORTIDebug
   osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[osdNumberOfAllTasks];
   osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbORTIServiceId[osdNumberOfAllTasks];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS
    #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
     osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[osdNumberOfAllTasks];
    #else
     #if osdLib
      osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[osdNumberOfAllTasks];
     #endif
    #endif
   #endif
#else
   osqTcbRAM1 osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[1];
   #if osdORTIDebug
   osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[1];
   osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbORTIServiceId[1];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS
   #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
   osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[1];
    #else
     #if osdLib
      osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[1];
     #endif
   #endif
   #endif
#endif


   #if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[osdNumberOfAllResources];
   #endif /* ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) */
   #if STATUS_LEVEL == EXTENDED_STATUS && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[osdNumberOfAllResources];
   #endif
   #if ((STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))) || osdORTIDebug
      osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[osdNumberOfAllResources];
   #endif


#if (osdNumberOfExtendedTasks > 0) || osdLib
   #if (osdNumberOfExtendedTasks == 0) && osdLib
   osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[1];
   #else
   osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[osdNumberOfExtendedTasks];
   #endif
#endif

#if osdLib
   osqROM0 osqROM1 const osqROM2 osRTSizeType    osqROM3 oskRTSize= osdRTSize;
   osqROM0 osqROM1 const osqROM2 osAppModeIndexType osqROM3 oskNumberOfAppModes=   osdNumberOfAppModes;
   osqROM0 osqROM1 const osqROM2 osTaskIndexType osqROM3 oskNumberOfAllTasks=      osdNumberOfAllTasks;
   osqROM0 osqROM1 const osqROM2 osTaskIndexType osqROM3 oskNumberOfExtendedTasks= osdNumberOfExtendedTasks;
   osqROM0 osqROM1 const osqROM2 osPrioType      osqROM3 oskNumberOfPriorities=    osdNumberOfPriorities;

   osqROM0 osqROM1 const osqROM2 osResourceIndexType osqROM3 oskNumberOfAllResources=       osdNumberOfAllResources;
   osqROM0 osqROM1 const osqROM2 osResourceIndexType osqROM3 oskNumberOfTaskResources=      osdNumberOfTaskResources;
   osqROM0 osqROM1 const osqROM2 osResourceIndexType osqROM3 oskNumberOfInterruptResources= osdNumberOfInterruptResources;
   osqROM0 osqROM1 const osqROM2 osResourceIndexType osqROM3 oskNumberOfInternalResources=  osdNumberOfInternalResources;

   osqROM0 osqROM1 const osqROM2 osAlarmIndexType osqROM3 oskNumberOfAlarms=       osdNumberOfAlarms;
   osqROM0 osqROM1 const osqROM2 osAlarmIndexType osqROM3 oskNumberOfVarAlarms=    osdNumberOfVarAlarms;
   
   osqROM0 osqROM1 const osqROM2 ScheduleTableType osqROM3 oskNumberOfScheduleTables=    osdNumberOfScheduleTables;
   osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskSystemTimer=                     SystemTimer;
   osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskNumberOfCounters=                osdNumberOfCounters;
   
   osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskMaxAllowedValue=    (TickType)OSMAXALLOWEDVALUE;
   osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskMinCycle=                     OSMINCYCLE;
   osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskTicksPerBase=                 OSTICKSPERBASE;

#endif
#if osdLib
   const osStackSizeType oskSystemStackSize= osdSystemStackSize;
#endif

#if (osdNumberOfCat2ISRs > 0)
   osIsrStoredInfoType osIsrStoredInfo[osdNumberOfCat2ISRs];
#else
   osIsrStoredInfoType osIsrStoredInfo[1];
#endif

/* End of invariant part */
#if defined osdUseGeneratedFastAlarm
#if ( (0==osdUserDefinedSystemTimer) && (osdAlarmsOnSystemTimer!=0) )
/* MISRA RULE 8.10 VIOLATION: Depending on the configuration, this function may be called only in this module.
 * Declaring this function static for some configurations would increase code complexity, too much. */
osqFunc1 void osqFunc2 osWorkAlarms(void) /* PRQA S 1505 */
{
   osqPRAM1 osqPRAM2 TickType osqPRAM3 *aPtr = osAlarmTime;
   osSaveDisableLevel();
   OS_TI_START_CRITICAL()
   if ((*aPtr) != 0)    /* Alarm_10ms */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_10ms is expired */
         (*aPtr) = ((TickType) 10UL )/*MSEC( 10 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_10ms] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_10ms);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_100ms */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_100ms is expired */
         (*aPtr) = ((TickType) 100UL )/*MSEC( 100 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_100ms] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_100ms);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_SCHM_TASK_CYCLE_10MS */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_SCHM_TASK_CYCLE_10MS is expired */
         (*aPtr) = ((TickType) 10UL )/*MSEC( 10 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_SCHM_TASK_CYCLE_10MS] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(SCHM_TASK_CYCLE_10MS);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_1000ms */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_1000ms is expired */
         (*aPtr) = ((TickType) 1000UL )/*MSEC( 1000 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_1000ms] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_1000ms);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_1ms */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_1ms is expired */
         (*aPtr) = ((TickType) 1UL )/*MSEC( 1 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_1ms] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_1ms);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_10ms_XCP */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_10ms_XCP is expired */
         (*aPtr) = ((TickType) 10UL )/*MSEC( 10 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_10ms_XCP] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_10ms_XCP);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_100ms_XCP */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_100ms_XCP is expired */
         (*aPtr) = ((TickType) 100UL )/*MSEC( 100 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_100ms_XCP] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_100ms_XCP);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }

   aPtr+=1;

   if ((*aPtr) != 0)    /* Alarm_1ms_XCP */
   {
      (*aPtr)--;
      if ((*aPtr) == 0)
      {
         /* Alarm_1ms_XCP is expired */
         (*aPtr) = ((TickType) 1UL )/*MSEC( 1 )*/;
#if (osdUseHeapAlarm != 0)
         if( (*aPtr) == 0 )
         {
            osAlarmActivated[Alarm_1ms_XCP] = 0;
         }
#endif /*osdUseHeapAlarm*/
         (void) osSysActivateTask(Task_1ms_XCP);

         OS_TI_END_CRITICAL()
         osRestoreEnableLevel();  /* enable interrupts */
         osSaveDisableLevel();  /* disable interrupts */
         OS_TI_START_CRITICAL()

      }
   }
   OS_TI_END_CRITICAL()
   osRestoreEnableLevel();
} /* END OF alarm checking function */
#endif /* ( (0==osdUserDefinedSystemTimer) &&  ((osdAlarmsOnSystemTimer)||(osdProvideTimeStamp != 0))) */
#endif /* osdUseGeneratedFastAlarm */



#pragma section all "osStacks"
#pragma align 4
osqStack1 osqStack2 osStackDataType  osqStack3 osSystemStack[ osdSystemStackSize/sizeof(osStackDataType) ];
#if (osdStackModel == osdSingleStackOsek)
osqStack1 osqStack2 osStackDataType osqStack3 osCat1IsrStack[ osdCat1IsrStackSize/sizeof(osStackDataType) ];
#endif /*(osdStackModel == osdSingleStackOsek)*/

/* Task stacks generated in dependence on the stack model: */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack0 [256]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack1 [256]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack2 [256]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack3 [256]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack4 [256]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack5 [32]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack6 [32]; /* PRQA S 1504 */
/* MISRA RULE 8.10 not violated: The task stacks are accessed by assembly language code.
 * This is not detected by the analysis tool.
 */
osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack7 [32]; /* PRQA S 1504 */
#pragma align restore
#pragma section all restore


/* Normal stack model, basic tasks have own or shared stacks */
/* Arrays oskTcbStackTop and oskTcbStackBottom for all tasks */

osqROM0 osStackPtrType osqROM1 const osqROM2 osqROM3 oskTcbStackTop[osdNumberOfAllTasks]=
{
   osAssignStack(osTaskStack0),
   osAssignStack(osTaskStack1),
   osAssignStack(osTaskStack2),
   osAssignStack(osTaskStack3),
   osAssignStack(osTaskStack4),
   osAssignStack(osTaskStack5),
   osAssignStack(osTaskStack6),
   osAssignStack(osTaskStack7),
};

#if osdStackCheck
osqROM0 osStackPtrType osqROM1 const osqROM2 osqROM3 oskTcbStackBottom[osdNumberOfAllTasks]=
{
   osBottomOfStack(osTaskStack0),
   osBottomOfStack(osTaskStack1),
   osBottomOfStack(osTaskStack2),
   osBottomOfStack(osTaskStack3),
   osBottomOfStack(osTaskStack4),
   osBottomOfStack(osTaskStack5),
   osBottomOfStack(osTaskStack6),
   osBottomOfStack(osTaskStack7),
};

#endif

#if (CC == BCC2) || (CC == ECC2)
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_0[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_1[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_2[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_3[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_4[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_5[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_6[2];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_7[16];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_8[16];
static osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQTaskActivation_9[16];

osqROM0 osqPTcbRAM1 osqPTcbRAM2 TaskType osqPTcbRAM3 * osqROM1 const osqROM2 osqROM3 oskQActivationQueues[osdNumberOfPriorities]=
{
   osQTaskActivation_0,
   osQTaskActivation_1,
   osQTaskActivation_2,
   osQTaskActivation_3,
   osQTaskActivation_4,
   osQTaskActivation_5,
   osQTaskActivation_6,
   osQTaskActivation_7,
   osQTaskActivation_8,
   osQTaskActivation_9,
};

osqROM0 osqROM1 const osqROM2 osQEntryCountType osqROM3 oskQMaxActivations[osdNumberOfPriorities]=
{
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   15,
   15,
   15,
};

#endif

osqROM0 osTaskFctType osqROM1 const osqROM2 osqROM3 oskTcbTaskStartAddress[osdNumberOfAllTasks] = {
   Task_1msfunc,
   Task_10msfunc,
   SCHM_TASK_CYCLE_10MSfunc,
   Task_100msfunc,
   Task_1000msfunc,
   Task_1ms_XCPfunc,
   Task_10ms_XCPfunc,
   Task_100ms_XCPfunc,
};

#if osdMixedPreempt
osqROM0 osqROM1 const osqROM2 osTaskPreemptionType osqROM3 oskTcbTaskPreemption[osdNumberOfAllTasks] = {
   osdTaskTypeNonPreempt,
   osdTaskTypeNonPreempt,
   osdTaskTypeNonPreempt,
   osdTaskTypeNonPreempt,
   osdTaskTypeNonPreempt,
   osdTaskTypePreempt,
   osdTaskTypePreempt,
   osdTaskTypePreempt,
};
#endif /* osdMixedPreempt */

osqROM0 osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[osdNumberOfAllTasks] = {
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
 osdTaskFlagNotUsingSchedule,
};

osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskTcbAutoStart[osdNumberOfAllTasks] = {
   0x00, /* Task_1ms */
   0x00, /* Task_10ms */
   0x00, /* SCHM_TASK_CYCLE_10MS */
   0x00, /* Task_100ms */
   0x00, /* Task_1000ms */
   0x00, /* Task_1ms_XCP */
   0x00, /* Task_10ms_XCP */
   0x00, /* Task_100ms_XCP */
};

osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskTcbReadyPrioMask[osdNumberOfAllTasks] = {
   0x40000000UL,
   0x20000000UL,
   0x10000000UL,
   0x08000000UL,
   0x04000000UL,
   0x01000000UL,
   0x00800000UL,
   0x00400000UL,
};

#if (osdRTSize > 1)
osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskTcbReadyPrioOffset[osdNumberOfAllTasks] = {
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
   0x00,
};
#endif

osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskTcbHomePrio[osdNumberOfAllTasks]=
{
   1,
   2,
   3,
   4,
   5,
   7,
   8,
   9,
};

#if (CC == BCC2) || (CC == ECC2)
osqROM0 osqROM1 const osqROM2 osActivationCountType osqROM3 oskTcbAllowedActivations[osdNumberOfAllTasks]=
{
   1,
   1,
   1,
   1,
   1,
   15,
   15,
   15,
};
#endif

#if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
#if (osdNumberOfAllTasks > 0)
   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[osdNumberOfAllTasks];
#else
   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[1];
#endif
#endif

/* Resources */

#if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
#if (STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions
osqROM0 osqROM1 const osqROM2 osResAccessMaskType osqROM3 oskResAccessMask[osdNumberOfAllResources][1]=
{
/* sequence of taskNumbers (!not priorities) */
   {    0xd8000000UL,   } /* COOPERATE*/
  ,{    0x07000000UL,   } /* XCP*/
};

#endif /* (STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions */

osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[osdNumberOfAllResources]=
{
   (osPrioType)0, /* COOPERATE*/
   (osPrioType)6, /* XCP*/
};

#if (0==osdNumberOfTaskResources)
osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[1]=
{
   0U
};

#else
osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[osdNumberOfTaskResources]=
{
   0x80000000UL,
   0x02000000UL,
};

#endif
#if (osdRTSize > 1)
#if (0==osdNumberOfTaskResources)
osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[1]=
{
   0
};
#else
osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[osdNumberOfTaskResources]=
{
   0x00,
   0x00,
};
#endif
#endif

#endif /* ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) */

#if (osdNumberOfAllTasks>0)
#if ((osdNumberOfInternalResources > 0)||(osdLib==1))
osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResInternalCeilingPrio[osdNumberOfAllTasks]=
{
   (osPrioType) 0,
   (osPrioType) 0,
   (osPrioType) 0,
   (osPrioType) 0,
   (osPrioType) 0,
   (osPrioType) 0,
   (osPrioType) 0,
   (osPrioType) 0,
};

osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResInternalCeilingPrioMask[osdNumberOfAllTasks]=
{
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};

 #if ((osdRTSize > 1)||(osdLib==1))
osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResInternalCeilingPrioOffset[osdNumberOfAllTasks]=
{
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};

#endif
#endif

#else
osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResInternalCeilingPrio[1]={0};
osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResInternalCeilingPrioMask[1]={0};
osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResInternalCeilingPrioOffset[1]={0};
#endif
#if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
#if (osdNumberOfAllResources > 0)
   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[osdNumberOfAllResources];
#else
   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[1];
#endif
#endif

/* Counters */

osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskCounterMaxAllowedValue[1]={
(TickType) OSMAXALLOWEDVALUE,
};
/*-+--------------------------------------------------------------------------
 / IncrementCounter                                                           
 / ================                                                           
 /                                                                            
 / Syntax:                                                                    
 /    StatusType IncrementCounter(CounterType CounterID)                      
 / Parameter (In):                                                            
 /   CounterType CounterID                                                    
 / Parameter (Out):                                                           
 /   none                                                                     
 / Description:                                                               
 /   This service increments the counter <CounterID> by one. If any alarm time
 /   or schedule table expiry point is reached by this increment, the         
 /   configured action (e.g. task activation) is performed.                   
 / Return value (depends on OIL-Attribute STATUS):                            
 /    STANDARD:                                                               
 /       - No error, E_OK                                                     
 /    EXTENDED:                                                               
 /       - <CounterID> not valid, E_OS_ID                                     
 /       - The service has been called with interrupts disabled,              
 /         E_OS_DISABLEDINT                                                   
 / Scalability Classes:                                                       
 /    SC1, SC2, SC3, SC4                                                      
 /--------------------------------------------------------------------------*/

/*
 * Sorry, no function IncrementCounter was generated, as no software counter exists.
 * (Only software counters can be incremented!)
 */

/* Alarms */

#if (osdNumberOfAlarmActivateTask > 0) || (osdNumberOfAlarmSetEvent > 0)
/* task to activate or to event */
osqROM0 osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[osdNumberOfAlarms]={
   Task_10ms, /* Alarm_10ms*/
   Task_100ms, /* Alarm_100ms*/
   SCHM_TASK_CYCLE_10MS, /* Alarm_SCHM_TASK_CYCLE_10MS*/
   Task_1000ms, /* Alarm_1000ms*/
   Task_1ms, /* Alarm_1ms*/
   Task_10ms_XCP, /* Alarm_10ms_XCP*/
   Task_100ms_XCP, /* Alarm_100ms_XCP*/
   Task_1ms_XCP, /* Alarm_1ms_XCP*/
};
#else
 #if osdLib
 osqROM0 osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[1]={0};
 #endif
#endif

#if osdNumberOfAlarmSetEvent > 0
osqROM0 osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[osdNumberOfAlarms]={
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
   0, /* 0 for ActivateTask or ALARMCALLBACK */
};
#else
 #if osdLib
 osqROM0 osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[1]={0};
 #endif
#endif

#if osdNumberOfAlarmCallback > 0
/* alarm callback function */
osqROM0 osAlarmCallbackType osqROM1 const osqROM2 osqROM3 oskAlarmCallback[osdNumberOfAlarms]={
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
   (osAlarmCallbackType) osdNULL,  /*lint !e611: "Suspicious cast", just a placeholder, never used as pointer */
};
#else
 #if osdLib
 osqROM0 osAlarmCallbackType osqROM1 const osqROM2 osqROM3 oskAlarmCallback[1]={(osAlarmCallbackType)0};
 #endif
#endif

#if ((osdNumberOfAlarmCallback > 0) || (osdNumberOfAlarmSetEvent > 0) || (osdNumberOfAlarmIncrementCounter > 0))
osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAction[osdNumberOfAlarms]={
   osdAlarmActionActivateTask, /* Alarm_10ms*/
   osdAlarmActionActivateTask, /* Alarm_100ms*/
   osdAlarmActionActivateTask, /* Alarm_SCHM_TASK_CYCLE_10MS*/
   osdAlarmActionActivateTask, /* Alarm_1000ms*/
   osdAlarmActionActivateTask, /* Alarm_1ms*/
   osdAlarmActionActivateTask, /* Alarm_10ms_XCP*/
   osdAlarmActionActivateTask, /* Alarm_100ms_XCP*/
   osdAlarmActionActivateTask, /* Alarm_1ms_XCP*/
};
#else
 #if osdLib
  osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAction[1]={0};
 #endif
#endif

 #if (osdNumberOfAlarmIncrementCounter > 0)
osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskAlarmIncrementCounterID[osdNumberOfAlarms]={
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
   0, /* 0 for all other actions */
};
#endif

/* static alarm time */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmTime[osdNumberOfAlarms]={
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_10ms*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_100ms*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_SCHM_TASK_CYCLE_10MS*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_1000ms*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_1ms*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_10ms_XCP*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_100ms_XCP*/
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_1ms_XCP*/
};

/* static cycle time */
osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmCycleTime[osdNumberOfAlarms]={
   ((TickType) 10UL )/*MSEC( 10 )*/, /* static alarm: Alarm_10ms */
   ((TickType) 100UL )/*MSEC( 100 )*/, /* static alarm: Alarm_100ms */
   ((TickType) 10UL )/*MSEC( 10 )*/, /* static alarm: Alarm_SCHM_TASK_CYCLE_10MS */
   ((TickType) 1000UL )/*MSEC( 1000 )*/, /* static alarm: Alarm_1000ms */
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_1ms */
   ((TickType) 10UL )/*MSEC( 10 )*/, /* static alarm: Alarm_10ms_XCP */
   ((TickType) 100UL )/*MSEC( 100 )*/, /* static alarm: Alarm_100ms_XCP */
   ((TickType) 1UL )/*MSEC( 1 )*/, /* static alarm: Alarm_1ms_XCP */
};

/* Autostart */
osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAutoStart[osdNumberOfAlarms]={
   0x01, /* Alarm_10ms*/
   0x01, /* Alarm_100ms*/
   0x00, /* Alarm_SCHM_TASK_CYCLE_10MS */
   0x01, /* Alarm_1000ms*/
   0x01, /* Alarm_1ms*/
   0x01, /* Alarm_10ms_XCP*/
   0x01, /* Alarm_100ms_XCP*/
   0x01, /* Alarm_1ms_XCP*/
};


#if (osdSystemCounterNeeded)


void osInitTimer(void)
{
#if (osdSystemTimer == osdGPTU_T0)
   osGPTU_T012RUN &= 0xFFFFFFF0UL; /*stop timer T0*/
   osGPTU_T01IRS = (osGPTU_T01IRS & 0x00F0FF00UL) | 0xA00700FCUL;
   /*select negative edge of input 0           */
   /*concatenate A-, B-, C- & D-blocks(32-bit) */
   /*reload all blocks on overflow of D-block  */
   /*select mod_clk as A-block clock input     */
   osGPTU_T0DCBA  = osdSystemTimerReloadValue;/*initial load value for count register*/
   osGPTU_T0RDCBA = osdSystemTimerReloadValue;/*reload register (T0 is upcounting)*/
   osGPTU_T01OTS = (osGPTU_T01OTS & 0x0FFF00FFUL) | 0x00000300UL;
   /*overflow of block D triggers SR00*/
   osGPTU_SRSEL = 0xC0000000UL;/*assign GTSRC0 the source SR00*/
   osGPTU_SRC0 = 0x00005000UL | osdAlarmLevel; /*enable service request node 0, &*/
   /*select CPU service, priority number osdAlarmLevel*/
   osGPTU_T012RUN |= 0x0000000FUL; /*start timer T0*/
   /*now T0 is running, an overflow of T0 will generate an interrupt*/
#elif (osdSystemTimer == osdGPTU_T1 )
   osGPTU_T012RUN &= 0xFFFFFF0FUL; /*stop timer T1*/
   osGPTU_T01IRS = (osGPTU_T01IRS & 0x000F00FFUL) | 0xA070FC00UL;
   /*select negative edge of input 0           */
   /*concatenate A-, B-, C- & D-blocks(32-bit)*/
   /*reload all blocks on overflow of D-block*/
   /*select mod_clk as A-block clock input*/
   osGPTU_T1DCBA  = osdSystemTimerReloadValue;/*initial load value for count register*/
   osGPTU_T1RDCBA = osdSystemTimerReloadValue;/*reload register (T1 is upcounting)*/
   osGPTU_T01OTS = (osGPTU_T01OTS & 0x00FFFFFFUL) | 0x03000000UL;
   /*overflow of block D triggers SR10*/
   osGPTU_SRSEL = 0x0E000000UL;/*assign GTSRC1 the source SR10*/
   osGPTU_SRC1 = 0x00005000UL | osdAlarmLevel; /*enable service request node 1, &*/
   /*select CPU service, priority number osdAlarmLevel*/
   osGPTU_T012RUN |= 0x000000F0; /* start timer T1*/
   /* now T1 is running, an overflow of T1 will generate an interrupt*/
#elif (osdSystemTimer == osdGPTU_T2 )
   osGPTU_T012RUN |= 0x00004400UL; /* stop timer T2*/
   osGPTU_T2CON = 0; /* count up, no split, count input module clock,*/
   osGPTU_T2RCCON = 0x00040004UL; /* reload on overflow of T2B from RC0*/
   osGPTU_T2AIS = 0;  /* no external input*/
   osGPTU_T2BIS = 0; /* no external input*/
   osGPTU_T2ES = 0; /* no external input*/
   osGPTU_T2    = osdSystemTimerReloadValue; /* reload value */
   osGPTU_T2RC0 = osdSystemTimerReloadValue;/*  reload value*/
   osGPTU_SRSEL = 0x00700000UL;/*assign GTSRC2 the source OUV_T2B*/
   osGPTU_SRC2 = 0x00005000UL | osdAlarmLevel; /*enable service request node 2, &*/
   /*select CPU service, priority number osdAlarmLevel*/
   osGPTU_T012RUN |= 0x00000200; /* start timer T2*/
   /* now T2 is running, an overflow of T2 will generate an interrupt*/
#elif (osdSystemTimer == osdSTM_CMP0 )
   /*using CMP0 and SRC0 registers, CMP1 and SRC1 are free*/
   osSTM_CMCON = (osSTM_CMCON & 0xFFFF0000UL) | osdSTM_CMCON_VAL;
   osSTM_CMP0  = osSTM_TIMER_READ + osdSystemTimerReloadValue;
   osSTM_ISRR  = 0x00000001UL;                     /*reset interrupt request*/
   osSTM_SRC0  = 0x00005000UL | osdAlarmLevel;       /*enable interupt, set level*/
#ifdef USE_TC1796_A_STEP
   /*output selection bit has different meaning on TC1796 A-Step*/
   osSTM_ICR   = ( osSTM_ICR& 0xFFFFFFF0UL) |  0x5 ; /*use SRC0, enable compare interrupt*/
#else
   osSTM_ICR   = ( osSTM_ICR& 0xFFFFFFF0UL) |  0x1 ; /*use SRC0, enable compare interrupt*/
#endif
#elif (osdSystemTimer == osdSTM_CMP1 )
   /*using CMP1 and SRC1 registers, CMP0 and SRC0 are free*/
   osSTM_CMCON = (osSTM_CMCON & 0x0000FFFF) | osdSTM_CMCON_VAL;
   osSTM_CMP1  = osSTM_TIMER_READ + osdSystemTimerReloadValue;
   osSTM_ISRR  = 0x00000004UL;                     /*reset interrupt request*/
   osSTM_SRC1  = 0x00005000UL | osdAlarmLevel;       /*enable interupt, set level*/
#ifdef USE_TC1796_A_STEP
   /*output selection bit has different meaning on TC1796 A-Step*/
   osSTM_ICR   = ( osSTM_ICR& 0xFFFFFF0FUL) | 0x10 ; /*use SRC1, enable compare interrupt*/
#else
   osSTM_ICR   = ( osSTM_ICR& 0xFFFFFF0FUL) | 0x50 ; /*use SRC1, enable compare interrupt*/
#endif
#endif /* (osdSystemTimer == ...) */
} /* END OF osInitTimer */

#endif /* (osdSystemCounterNeeded) */

/* Schedule Tables */

#if (osdNumberOfScheduleTables > 0)
osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskCounterOfST[osdNumberOfScheduleTables]={
};

#if (osdScheduleTableSyncUsed!=0)
/* Length of ScheduleTable/Period of GlobalTime*/
osqROM0 osqROM1 const osqROM2 GlobalTimeTickType osqROM3 oskSTMaxAllowed[osdNumberOfScheduleTables]={
};
#endif

/* The array oskScheduleTableInitialOffset is only just necessary to 
 * fullfill [SR:189] our implementation does no longer need it */
   osqROM0 osqROM1 const osqROM2 osSTOffsetType osqROM3 oskScheduleTableInitialOffset[osdNumberOfScheduleTables]={
   
};
#else
   osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskCounterOfST[1] = {0};
   osqROM0 osqROM1 const osqROM2 osSTOffsetType osqROM3 oskScheduleTableInitialOffset[1] = {0};
#endif /*(osdNumberOfScheduleTables > 0)*/

#if (osdNumberOfSTEntries > 0)
osqFunc1 osSTReactionType osqFunc2 osSTWorkActions(GlobalTimeTickType* diff, osSTIndexType CurrentEP)
{
   switch (CurrentEP)
   {
      /* MISRA RULE 14.1 VIOLATION: Some statements in the assertion might be not
       * reachable but this is the only way for secure usage of internal assertion API (3201)
       * This is also the reason for usage of the <always true> expression (3346, no MISRA error)  */
      default:
         osSysErrAssert(osdFALSE, osdErrWSUnknownAction)  /* PRQA S 3346 */
         return osdSTReact_Stop;  /* PRQA S 3201 */
   }
}
#endif /*(osdNumberOfSTEntries > 0)*/

#if (osdNumberOfScheduleTables > 0)
osqROM0 osqROM1 const osqROM2 osSTIndexType osqROM3 oskSTStartIndex[osdNumberOfScheduleTables]={
};
#else
   osqROM0 osqROM1 const osqROM2 osSTIndexType osqROM3 oskSTStartIndex[1] = {0};
#endif /*(osdNumberOfScheduleTables > 0)*/

#if (STATUS_LEVEL == EXTENDED_STATUS)
#endif /*(STATUS_LEVEL == EXTENDED_STATUS)*/
/* Hook routines */

#if ((defined osdTestMacros) || osdLib || (osdSC== SC3) || (osdSC== SC4))

#if osdPreTaskHook/* MISRA RULE 14.1 not violated: osInterPreTaskHook might be called from assembly on 
 * some platforms. (1503) */

osqFunc1 void osqFunc2 osInterPreTaskHook(void) /* PRQA S 1503 */
{
} /* END OF osInterPreTaskHook */
#endif

#if osdPostTaskHook/* MISRA RULE 14.1 not violated: osInterPostTaskHook might be called from assembly on 
 * some platforms. (1503) */

osqFunc1 void osqFunc2 osInterPostTaskHook(void) /* PRQA S 1503 */
{
} /* END OF osInterPostTaskHook */
#endif
#endif /*((defined osdTestMacros) || osdLib || (osdSC== SC3) || (osdSC== SC4))*/

#if (osdLib || (osdSC== SC3) || (osdSC== SC4))
/* MISRA RULE 14.1 VIOLATION: osInterErrorHook might be not called in some
 * configurations. Conditional compiling of the function would increase
 * the code complexity to unacceptable level (1503) */
void osInterErrorHook(StatusType Error)   /* PRQA S 1503 */
{
#if ((osdSC== SC3) || (osdSC== SC4))
   osInSystemFct++;
#endif
   ErrorHook(Error);
#if ((osdSC== SC3) || (osdSC== SC4))
   osInSystemFct--;
#endif
} /* END OF osInterErrorHook */
/* MISRA RULE 14.1 VIOLATION: osInterStartupHook might be not called in some
 * configurations. Conditional compiling of the function would increase
 * the code complexity to unacceptable level (1503) */

void osInterStartupHook(void)   /* PRQA S 1503 */
{
#if ((osdSC== SC3) || (osdSC== SC4))
   osuint16 savedContext;

   osInSystemFct = osdTRUE;
   savedContext = osCurrentContext;
   osCurrentContext = osdCtxStartupHook;
#endif
   StartupHook();
#if ((osdSC== SC3) || (osdSC== SC4))
   osCurrentContext = savedContext;
   osInSystemFct = osdFALSE;
#endif
} /* END OF osInterStartupHook */
/* MISRA RULE 14.1 VIOLATION: osInterShutdownHook might be not called in some
 * configurations. Conditional compiling of the function would increase
 * the code complexity to unacceptable level (1503) */

osqFunc1 void osqFunc2 osInterShutdownHook(StatusType Error)   /* PRQA S 1503 */
{
#if ((osdSC== SC3) || (osdSC== SC4))
   osuint16 savedContext;

   osInSystemFct = osdTRUE;
   savedContext = osCurrentContext;
   osCurrentContext = osdCtxShutdownHook;
#endif
   ShutdownHook(Error);
#if ((osdSC== SC3) || (osdSC== SC4))
   osCurrentContext = savedContext;
   osInSystemFct = osdFALSE;
#endif
} /* END OF osInterShutdownHook */
/* MISRA RULE 14.1 VIOLATION: osInterCOMErrorHook might be not called in some
 * configurations. Conditional compiling of the function would increase
 * the code complexity to unacceptable level (1503) */

osqFunc1 void osqFunc2 osInterCOMErrorHook(StatusType Error)   /* PRQA S 1503 */
{
   osdDummyRead(Error)
} /* END OF osInterCOMErrorHook */

#endif
#if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
#if (osdNumberOfCat2ISRs > 0)
   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[osdNumberOfCat2ISRs];
#else
   osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[1];
#endif
#endif


/* END OF C:\OS\OS2.0\tcb\tcb.c */
