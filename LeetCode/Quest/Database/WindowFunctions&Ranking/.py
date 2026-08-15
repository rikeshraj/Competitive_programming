# Q1. Trips and Users
# The cancellation rate is computed by dividing the number of canceled (by client or driver) requests with unbanned users by the total number of requests with unbanned users on that day.
# Write a solution to find the cancellation rate of requests with unbanned users (both client and driver must not be banned) each day between "2013-10-01" and "2013-10-03" with at least one trip. Round Cancellation Rate to two decimal points.
def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    valid_users = users[users["banned"] == "No"]["users_id"]
    df = trips[
        trips["client_id"].isin(valid_users) &
        trips["driver_id"].isin(valid_users)
    ]
    df = df[
        (df["request_at"] >= "2013-10-01") &
        (df["request_at"] <= "2013-10-03")
    ]
    result = (
        df.assign(cancelled=(df["status"] != "completed").astype(int))
          .groupby("request_at")
          .agg(
              cancelled=("cancelled", "sum"),
              total=("status", "count")
          )
          .reset_index()
    )
    result["Cancellation Rate"] = (
        result["cancelled"] / result["total"]
    ).round(2)
    return result[
        ["request_at", "Cancellation Rate"]
    ].rename(columns={"request_at": "Day"})

# 


# 


