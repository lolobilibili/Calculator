import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import matplotlib.dates as mdates

def gantt_graph(tasks_str,dates_str,durations_str):
    # Step 2: Create the data for the Gantt chart
    tasks = list(tasks_str.split("|"))
    start_dates = list(dates_str.split("|"))
    durations = list(durations_str.split("|"))
    for i in range(len(durations)):
        durations[i] = int(durations[i])

    # Step 3: Initialize the figure and axis
    fig, ax = plt.subplots()

    # Step 4: Set y-axis tick labels
    ax.set_yticks(np.arange(len(tasks)))
    ax.set_yticklabels(tasks)

    # Step 5: Plot each task as a horizontal bar
    for i in range(len(tasks)):
        start_date = pd.to_datetime(start_dates[i])
        end_date = start_date + pd.DateOffset(days=durations[i])
        ax.barh(i, end_date - start_date, left=start_date, height=0.5, align='center')

    # Step 6: Set x-axis limits
    min_date = pd.to_datetime(min(start_dates))
    max_date = pd.to_datetime(max(start_dates)) + pd.DateOffset(days=max(durations))
    ax.set_xlim(min_date, max_date)

    # Step 7: Customize the chart
    ax.xaxis_date()
    ax.xaxis.set_major_locator(mdates.WeekdayLocator())
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d'))
    ax.set_xlabel('Date')
    ax.set_ylabel('Tasks')
    ax.set_title('Basic Gantt Chart')

    # Step 8: Display the chart
    plt.grid(True)
    plt.show()
    return